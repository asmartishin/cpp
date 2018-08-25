#pragma once

#include <memory>

namespace NLinkedList {
    template<typename T>
    class LinkedList {
    private:
        struct Node {
            std::unique_ptr<Node> Next;
            T Data;

            explicit Node(const T &data)
                    : Data(data) {}
        };

        template <bool Const = true>
        class LinkedListIterator {
        private:
            Node* NodePtr;
        public:
            explicit LinkedListIterator(Node* node)
                : NodePtr(node)
            {}

            LinkedListIterator(const LinkedListIterator& other)
                : NodePtr(other.NodePtr)
            {}

            LinkedListIterator& operator=(LinkedListIterator other) {
                std::swap(NodePtr, other.NodePtr);
                return *this;
            }

            LinkedListIterator& operator++() {
                NodePtr = NodePtr->Next.get();
                return *this;
            }

            const LinkedListIterator operator++(int) {
                LinkedListIterator it(*this);
                NodePtr = NodePtr->Next.get();
                return it;
            }

            bool operator==(const LinkedListIterator& other) const noexcept {
                return NodePtr == other.NodePtr;
            }

            bool operator!=(const LinkedListIterator& other) const noexcept {
                return !(*this == other);
            }

            typename std::conditional<Const, const T&, T&>::type operator*() const {
                return NodePtr->Data;
            }
        };

        std::unique_ptr<Node> Head;
        Node *Tail = nullptr;
        std::size_t Size_ = 0;

    public:
        using iterator = LinkedListIterator<false>;
        using const_iterator = LinkedListIterator<true>;

        LinkedList() = default;

        LinkedList(std::initializer_list<T> list) {
            for (const T &data: list) {
                PushBack(data);
            }
        }

        LinkedList(const LinkedList& other) {
            for (auto it = other.cbegin(); it != other.cend(); ++it) {
                PushBack(*it);
            }
        }

        LinkedList& operator=(LinkedList other) {
            swap(*this, other);
            return *this;
        }

        LinkedList(LinkedList&& other) noexcept
            : Head(std::move(other.Head))
        {
            Tail = other.Tail;
            other.Tail = nullptr;
            Size_ = other.Size_;
            other.Size_ = 0;
        }

        LinkedList& operator=(LinkedList&& other) noexcept {
            if(this!=&other) {
                Head = std::move(other.Head);
                other.Head = nullptr;
                Tail = other.Tail;
                other.Tail = nullptr;
                Size_ = other.Size_;
                other.Size_ = 0;
            }
            return *this;
        }

        void PushBack(const T &data) {
            if (Tail) {
                Tail->Next = std::make_unique<Node>(data);
                Tail = Tail->Next.get();
            } else {
                Head = std::make_unique<Node>(data);
                Tail = Head.get();
            }
            ++Size_;
        }

        friend void swap(LinkedList& lhs, LinkedList& rhs) {
            std::swap(lhs.Size_, rhs.Size_);
            std::swap(lhs.Head, rhs.Head);
            std::swap(lhs.Tail, rhs.Tail);
        }

        iterator begin() {
            return iterator(Head.get());
        }

        iterator end() {
            return iterator(Tail->Next.get());
        }

        const_iterator cbegin() const {
            return const_iterator(Head.get());
        }

        const_iterator cend() const {
            return const_iterator(Tail->Next.get());
        }

        size_t Size() const noexcept {
            return Size_;
        }
    };
}

