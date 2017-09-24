#!/usr/bin/env python

from sys import stdin, stdout


class Table(object):
    def __init__(self):
        self._team_names = set()
        self._max_team_name = 0
        self._max_score = 0
        self.table = {}

    def insert_game(self, game):
        assert isinstance(game, Game)

        self._calculate_game_result(game.first_team, game.second_team, game.first_team_points, game.second_team_points)
        self._calculate_game_result(game.second_team, game.first_team, game.second_team_points, game.first_team_points)

    def _calculate_game_result(self, first_team, second_team, first_team_points, second_team_points):
        if first_team not in self.table:
            self._team_names.add(first_team)

            if len(first_team) > self._max_team_name:
                self._max_team_name = len(first_team)

            self.table[first_team] = {
                'games': {
                    first_team: 'X'
                },
                'score': 0,
                'number_of_wins': 0,
            }

        if first_team_points > second_team_points:
            self._set_game_result(first_team, second_team, 'W')
            self._set_game_score(first_team, 3)
            self._add_win(first_team)
        elif first_team_points < second_team_points:
            self._set_game_result(first_team, second_team, 'L')
        else:
            self._set_game_result(first_team, second_team, 'D')
            self._set_game_score(first_team, 1)

    def _set_game_result(self, first_team, second_team, state):
        self.table[first_team]['games'][second_team] = state

    def _set_game_score(self, team, score):
        self.table[team]['score'] += score
        if (self.table[team]['score']) > self._max_score:
            self._max_score = self.table[team]['score']

    def _add_win(self, team):
        self.table[team]['number_of_wins'] += 1

    def __str__(self):
        sorted_team_names = sorted(self._team_names)

        places = set()

        for team_name in sorted_team_names:
            team_data = self.table[team_name]
            places.add((team_data['score'], team_data['number_of_wins']))

        top_places = sorted(places, reverse=True)[:3]

        delimiter = '+' + '-' * (len(str(len(sorted_team_names)))) + '+' + '-' *  (self._max_team_name + 1) + '+' + \
            '-+' * len(sorted_team_names) + '-' * len(str(self._max_score)) + '+-+\n'
        result = delimiter

        for i, team_name in enumerate(sorted_team_names):
            team_data = self.table[team_name]
            line = '|'
            line += ' ' * (len(str(len(sorted_team_names))) - len(str(i + 1)))
            line += '{}|'.format(i + 1)
            line += team_name + ' ' * (self._max_team_name - len(team_name) + 1) + '|'
            for other_team_name in (sorted_team_names):
                if other_team_name in team_data['games']:
                    line += team_data['games'][other_team_name] + '|'
                else:
                    line += ' |'

            line += ' ' * (len(str(self._max_score)) - len(str(team_data['score'])))
            line += '{}'.format(str(team_data['score']))
            line += '|'

            place = self._get_place(team_data['score'], team_data['number_of_wins'], top_places)

            if place is not None:
                line += '{}|'.format(place + 1)
            else:
                line += ' |'

            result += line + '\n' + delimiter
        return result.rstrip()

    def _get_place(self, score, number_of_wins, top_places):
        for i, place in enumerate(top_places):
            if score == place[0] and number_of_wins == place[1]:
                return i
        return None

    def __repr__(self):
        return self.__str__()


class Game(object):
    def __init__(self, raw_game_data):
        game_data = raw_game_data.split()

        self.first_team = game_data[0]
        self.second_team = game_data[2]
        self.first_team_points = int(game_data[4].split(':')[0])
        self.second_team_points = int(game_data[4].split(':')[1])

    def __str__(self):
        return "{} - {} - {}:{}".format(
            self.first_team,
            self.second_team,
            self.first_team_points,
            self.second_team_points
        )

    def __repr__(self):
        return self.__str__()


if __name__ == '__main__':
    table = Table()

    games = map(lambda x: str(x).rstrip(), stdin.readlines())

    for game in games:
        table.insert_game(Game(game))

    print(table)
