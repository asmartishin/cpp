#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>


class TField {
    public:
        TField(std::string filename) {
            std::ifstream inFile(filename);
            inFile >> Height;
            inFile >> Width;
            inFile >> L;
            inFile >> H;

            Field = std::vector<std::vector<bool> >(Height);
            char inChar;

            for (int row = 0; row < Height; row++) {
                Field[row] = std::vector<bool>(Width);
		for (int col = 0; col < Width; col++) {
                    inFile >> inChar;
                    if (inChar == 'T') {
                        Field[row][col] = true;
                    } else {
                        Field[row][col] = false;
                    }
                }
            }

            inFile.close();
        }

        int GetHeight() const {
            return Height;
        }

        int GetWidth() const {
            return Width;
        }

        int GetL() const {
            return L;
        }

        int GetH() const {
            return H;
        }

        int GetValue(int row, int col) const {
            return Field.at(row).at(col);
        }

        const std::vector<std::pair<int, int> > GetAllSizes() const {
            std::vector<std::pair<int, int> > sizes;
            for (int area = 2 * L; area <= H; ++area) {
                for (int height = 1; height <= area; ++height) {
                    if (area % height == 0) {
                        sizes.push_back(std::make_pair(height, area / height));
                    }
                }
            }
            return sizes;
        }

    private:
        std::vector<std::vector<bool> > Field;

        int Height;
        int Width;

        int L; // L - number of ingredients of each type in slice
        int H; // H - maximum number of ingredients in slice
};


struct TPoint {
    TPoint(int row, int col) : Row(row), Col(col) {}

    int Row;
    int Col;

    bool operator==(const TPoint& other) const {
        return Row == other.Row && Col == other.Col;
    }

    bool operator!=(const TPoint& other) const {
        return !(*this == other);
    }
};

class TPointHash {
public:
    size_t operator() (const TPoint& point) const {
        std::string temp = (
            std::to_string(point.Row)
            + std::string("_") + std::to_string(point.Col)
        );
        return std::hash<std::string>()(temp);
    }
};

struct TRectangle {
    TRectangle(int row, int col, int height, int width) : Row(row), Col(col), Height(height), Width(width) {}

    int Row;
    int Col;

    int Height;
    int Width;

    TPoint GetPoint() const {
        return TPoint(Row, Col);
    }

    bool operator==(const TRectangle& other) const {
        return Row == other.Row && Col == other.Col && Width == other.Width && Height == other.Height;
    }

    bool operator!=(const TRectangle& other) const {
        return !(*this == other);
    }
    friend std::ostream& operator<<(std::ostream& out, const TRectangle& rectangle) {
        out << " row " << rectangle.Row << " col " << rectangle.Col << " height " << rectangle.Height << " width " << rectangle.Width;
        return out;
    }

    bool Intersects(const TRectangle& other) const {
        return !(
            Row + Height <= other.Row
            || Col + Width <= other.Col
            || Row >= other.Row + other.Height
            || Col >= other.Col + other.Width
        );
    }

    int GetArea() const {
        return Height * Width;
    }
};

class TRectangleHash {
public:
    size_t operator() (const TRectangle& rectangle) const {
        std::string temp = (
            std::to_string(rectangle.Row)
            + std::string("_") + std::to_string(rectangle.Col)
            + std::string("_") + std::to_string(rectangle.Height)
            + std::string("_") + std::to_string(rectangle.Width)
        );
        return std::hash<std::string>()(temp);
    }
};

class TRectangles {
private:
	std::unordered_set<TRectangle, TRectangleHash> RectIndex;
	std::unordered_map<TPoint, std::unordered_set<TRectangle, TRectangleHash> , TPointHash> PointToRectangle;

public:

    typedef std::unordered_set<TRectangle, TRectangleHash>::const_iterator iterator;
	void AddRect(const TRectangle& rect) {
		RectIndex.insert(rect);
		PointToRectangle[rect.GetPoint()].insert(rect);
	}

	iterator GetRectangleIteratorBegin() const {
		return RectIndex.begin();
	}

	iterator GetRectangleIteratorEnd() const {
		return RectIndex.end();
	}

    bool AreThereRectangles(const TPoint& point) const {
        return PointToRectangle.find(point) != PointToRectangle.end();
    }

	iterator GetRectangleOfPointIteratorBegin(TPoint point) const {
		return PointToRectangle.at(point).begin();
	}

	iterator GetRectangleOfPointIteratorEnd(TPoint point) const {
		return PointToRectangle.at(point).end();
	}

	void RemoveRect(const TRectangle rect) {
		RectIndex.erase(rect);
		PointToRectangle[rect.GetPoint()].erase(rect);
        if (PointToRectangle[rect.GetPoint()].size() == 0) {
            PointToRectangle.erase(rect.GetPoint());
        }
	}

	bool IsEmpty() const {
		return RectIndex.empty();
	}
};

class TPrefixRectIndex {
private:
	const TField& Field;
	std::vector<std::vector<std::pair<int, int> > > PrefMatrix;

public:
	TPrefixRectIndex(const TField& field)
		: Field(field)
		, PrefMatrix(field.GetHeight(), std::vector<std::pair<int, int> >(field.GetWidth(), std::make_pair(0,0)))
	{
		for (size_t x = 0; x < field.GetHeight(); ++x) {
			for (size_t y = 0; y < Field.GetWidth(); ++y) {
				if (y != 0) {
					PrefMatrix[x][y].first += PrefMatrix[x][y - 1].first;
					PrefMatrix[x][y].second += PrefMatrix[x][y - 1].second;
				}
				PrefMatrix[x][y].first += field.GetValue(x, y) ? 1 : 0;
				PrefMatrix[x][y].second += field.GetValue(x, y) ? 0 : 1;
			}
		}

		for (size_t x = 1; x < field.GetHeight(); ++x) {
			for (size_t y = 0; y < Field.GetWidth(); ++y) {
                PrefMatrix[x][y].first += PrefMatrix[x - 1][y].first;
                PrefMatrix[x][y].second += PrefMatrix[x - 1][y].second;
			}
		}
	}

    const std::pair<int, int> GetPrefPairOrZeros(const int row, const int col) const {
        if (row >= 0 && row < Field.GetHeight() && col >= 0 && col < Field.GetWidth()) {
            return PrefMatrix[row][col];
        } else {
            return std::make_pair(0, 0);
        }
    }


	bool IsRectOK(const TRectangle& rect) const {
		if (rect.Col + rect.Width <= Field.GetWidth() && rect.Row + rect.Height <= Field.GetHeight()) {
            std::pair<int, int> a = GetPrefPairOrZeros(rect.Row + rect.Height - 1, rect.Col + rect.Width - 1);
            std::pair<int, int> b = GetPrefPairOrZeros(rect.Row - 1, rect.Col - 1);
            std::pair<int, int> c = GetPrefPairOrZeros(rect.Row + rect.Height - 1, rect.Col - 1);
            std::pair<int, int> d = GetPrefPairOrZeros(rect.Row - 1, rect.Col + rect.Width - 1);
            std::pair<int, int> res = std::make_pair(a.first + b.first - c.first - d.first, a.second + b.second - c.second - d.second);
            return Field.GetH() >= rect.Height && Field.GetH() >= rect.Width && res.first >= Field.GetL() && res.second >= Field.GetL();
        } else {
            return false;
        }
	}

	void BuildRectangles(TRectangles& rects) {
		std::vector<std::pair<int, int>> sizes(Field.GetAllSizes());
		for (size_t row = 0; row < Field.GetHeight(); ++row) {
			for (size_t col = 0; col < Field.GetWidth(); ++col) {
				for (size_t i = 0; i < sizes.size(); ++i) {
					TRectangle rec(row, col, sizes[i].first, sizes[i].second);
					if (IsRectOK(rec)) {
						rects.AddRect(rec);
					}
				}
			}
		}
	}

};



class TIntersectionIndex {
public:
    TIntersectionIndex(
        const TField& Field,
        TRectangles& Rectangles
    )
    : Field(Field)
    , Rectangles(Rectangles)
    {
        Initialize();
    }

    void AddRectangleIfNotExists(const TRectangle& Rectangle) {
        if (!RectangleIntersection.count(Rectangle)) {
            RectangleIntersection[Rectangle] = 0;
            IntersectionRectangles[0].insert(Rectangle);
        }
    }

    void CleanupEmptyIndex(int intersections) {
        if (IntersectionRectangles[intersections].size() == 0) {
            IntersectionRectangles.erase(intersections);
        }
    }

    void DecreaseIntersectionsCount(const TRectangle& Rectangle) {
//        std::cout << "Before DecreaseIntersectionsCount " << Rectangle << " " << *this;
        int old_intersections_count = RectangleIntersection[Rectangle];
        --RectangleIntersection[Rectangle];
        IntersectionRectangles[old_intersections_count].erase(Rectangle);
        CleanupEmptyIndex(old_intersections_count);
        IntersectionRectangles[old_intersections_count - 1].insert(Rectangle);
//        std::cout << "After DecreaseIntersectionsCount " << Rectangle << " "  << *this;
    }

    void IncreaseIntersectionsCount(const TRectangle& Rectangle) {
//        std::cout << "Before IncreaseIntersectionsCount " << Rectangle << " " << *this;
        AddRectangleIfNotExists(Rectangle);
        int old_intersections_count = RectangleIntersection[Rectangle];
        ++RectangleIntersection[Rectangle];
        IntersectionRectangles[old_intersections_count].erase(Rectangle);
        CleanupEmptyIndex(old_intersections_count);
        IntersectionRectangles[old_intersections_count + 1].insert(Rectangle);
//        std::cout << "After IncreaseIntersectionsCount " << Rectangle << " "  << *this;
    }

    void Initialize() {
        for(
            TRectangles::iterator it = Rectangles.GetRectangleIteratorBegin();
            it != Rectangles.GetRectangleIteratorEnd();
            ++it
        ) {
            TAddingIntersectionVisitor addingIntersectionVisitor(*this, *it);
            addingIntersectionVisitor.Visit();
        }
//        std::cout << "After Initialize " << *this;
    }

    bool IsThereIntersectionsCount(const int intersections) {
        return IntersectionRectangles.count(intersections);
    }

    int GetMinIntersectionsCount() {
        int min_intersections = 1000000;
        for (
            auto it = IntersectionRectangles.begin();
            it != IntersectionRectangles.end();
            ++it
        ) {
            if (min_intersections >= it->first) {
                min_intersections = it->first;
            }
        }
        return min_intersections;
    }

    const TRectangle GetOneRectangle(const int intersections) {
        TRectangle targetRectangle(0, 0, 0, 0);
        int max_area = 0;
        for (
            auto it = IntersectionRectangles[intersections].begin();
            it != IntersectionRectangles[intersections].end();
            ++it
        ) {
            if (max_area < it->GetArea()) {
                max_area = it->GetArea();
                targetRectangle = *it;
            }
        }

        return targetRectangle;
    }

    void RemoveRectangle(const TRectangle& rectangle) {
//        std::cout << "Before RemoveRectangle " << rectangle << " " << *this;
        TRemovingIntersectionVisitor removingIntersectionVisitor(*this, rectangle);
        removingIntersectionVisitor.Visit();
        int intersections = RectangleIntersection[rectangle];
        IntersectionRectangles[intersections].erase(rectangle);
        CleanupEmptyIndex(intersections);
        RectangleIntersection.erase(rectangle);
        Rectangles.RemoveRect(rectangle);
//        std::cout << "After RemoveRectangle " << rectangle << " " << *this;
    }

    void RemoveRectangleAndNeighbours(const TRectangle& rectangle) {
//        std::cout << "Before RemoveRectangleAndNeighbours " << rectangle << " " << *this;
        TRemoveNeighhoursIntersectionVisitor(*this, rectangle).Visit();
        RemoveRectangle(rectangle);
//        std::cout << "After RemoveRectangleAndNeighbours " << rectangle << " " << *this;
    }

    bool IsEmpty() const {
        return Rectangles.IsEmpty();
    }

    friend std::ostream& operator<<(std::ostream& out, const TIntersectionIndex& intersectionIndex) {
        for (
            auto it = intersectionIndex.IntersectionRectangles.begin();
            it != intersectionIndex.IntersectionRectangles.end();
            ++it
        ) {
            auto rectanglesSet = it->second;
            for (
                auto it2 = rectanglesSet.begin();
                it2 != rectanglesSet.end();
                ++it2
            ) {
                out << "\n\tIntersectionRectangles " << " - " << it->first << " - " << *it2;
            }
        }

        for (
            auto it = intersectionIndex.RectangleIntersection.begin();
            it != intersectionIndex.RectangleIntersection.end();
            ++it
        ) {
            out << "\n\tRectangleIntersection " << " - " << it->first << " - " << it->second;
        }
        return out;
    }

private:
    const TField& Field;
    TRectangles& Rectangles;
    std::unordered_map<int, std::unordered_set<TRectangle, TRectangleHash> > IntersectionRectangles;
    std::unordered_map<TRectangle, int, TRectangleHash> RectangleIntersection;

    class TIntersectionVisitorBase {
    public:
        TIntersectionVisitorBase(TIntersectionIndex& Parent, const TRectangle& Rectangle)
        : Parent(Parent)
        , Rectangle(Rectangle)
        {}

        virtual void OnIntersected(const TRectangle& IntersectedRectangle) = 0;

        void Visit() {
            int minRow = std::max(0, Rectangle.Row - Parent.Field.GetH() - 1);
            int minCol = std::max(0, Rectangle.Col - Parent.Field.GetH() - 1);
            int maxRow = std::min(Rectangle.Row + Rectangle.Height, Parent.Field.GetHeight() - 1);
            int maxCol = std::min(Rectangle.Col + Rectangle.Width, Parent.Field.GetWidth() - 1);

            std::vector<TRectangle> neighbourRectangles;

            for (int row = minRow; row <= maxRow; ++row) {
                for (int col = minCol; col <= maxCol; ++col) {
                    if (Parent.Rectangles.AreThereRectangles(TPoint(row, col))) {
                        for(
                            TRectangles::iterator it = Parent.Rectangles.GetRectangleOfPointIteratorBegin(TPoint(row, col));
                            it != Parent.Rectangles.GetRectangleOfPointIteratorEnd(TPoint(row, col));
                            ++it
                        ) {
                            if (*it != Rectangle && it->Intersects(Rectangle)) {
                                neighbourRectangles.push_back(*it);
                            }
                        }
                    }
                }
            }

            for (auto it = neighbourRectangles.begin(); it != neighbourRectangles.end(); ++it) {
                OnIntersected(*it);
            }
        }

        virtual ~TIntersectionVisitorBase() {
        }
    protected:
        TIntersectionIndex& Parent;
        const TRectangle& Rectangle;
    };

    class TRemovingIntersectionVisitor : public TIntersectionVisitorBase {
    public:
        TRemovingIntersectionVisitor(TIntersectionIndex& Parent, const TRectangle& Rectangle)
        : TIntersectionVisitorBase(Parent, Rectangle)
        {}

        void OnIntersected(const TRectangle& IntersectedRectangle) {
            Parent.DecreaseIntersectionsCount(IntersectedRectangle);
        }
    };

    class TAddingIntersectionVisitor : public TIntersectionVisitorBase {
    public:
        TAddingIntersectionVisitor(TIntersectionIndex& Parent, const TRectangle& Rectangle)
        : TIntersectionVisitorBase(Parent, Rectangle)
        {}

        void OnIntersected(const TRectangle& IntersectedRectangle) {
            Parent.IncreaseIntersectionsCount(Rectangle);
        }
    };

    class TRemoveNeighhoursIntersectionVisitor : public TIntersectionVisitorBase {
    public:
        TRemoveNeighhoursIntersectionVisitor(TIntersectionIndex& Parent, const TRectangle& Rectangle)
        : TIntersectionVisitorBase(Parent, Rectangle)
        {}

        void OnIntersected(const TRectangle& IntersectedRectangle) {
            Parent.RemoveRectangle(IntersectedRectangle);
        }
    };
};

class TResponse {
public:
    TResponse(TIntersectionIndex& intersectionIndex, TRectangles& Rectangles)
    : IntersectionIndex(intersectionIndex)
    , Rectangles(Rectangles)
    {}

    void GetResult() {
        while (!IntersectionIndex.IsEmpty()) {
            int intersections = IntersectionIndex.GetMinIntersectionsCount();
            const TRectangle& rectangle = IntersectionIndex.GetOneRectangle(intersections);
            RectanglesArray.push_back(rectangle);
            IntersectionIndex.RemoveRectangleAndNeighbours(rectangle);
        }
    }

    void DumpResult() {
        std::ofstream out("output.txt");

        out << RectanglesArray.size() << std::endl;
        for (int i = 0; i < RectanglesArray.size(); ++i) {
            out << RectanglesArray[i].Row << " " << RectanglesArray[i].Col << " " << (RectanglesArray[i].Row + RectanglesArray[i].Height - 1) << " " << (RectanglesArray[i].Col + RectanglesArray[i].Width - 1) << std::endl;
        }

        out.close();
    }
private:
    TIntersectionIndex& IntersectionIndex;
    std::vector<TRectangle> RectanglesArray;
    TRectangles& Rectangles;
};

int main() {
    TField field("medium.in");
    TPrefixRectIndex prefixRectIndex(field);
    TRectangles rectangles;
    prefixRectIndex.BuildRectangles(rectangles);
    TIntersectionIndex intersectionIndex(field, rectangles);
    TResponse response(intersectionIndex, rectangles);
    response.GetResult();
    response.DumpResult();
    return 0;
}


