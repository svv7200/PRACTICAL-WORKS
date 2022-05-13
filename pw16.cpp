#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

typedef size_t                          T_town;

typedef std::vector     < T_town    >   T_path_val;

typedef int                             T_dist;

typedef std::vector     < T_dist    >   T_row;

typedef std::vector     < T_row     >   T_matr;

typedef std::set        < T_town    >   T_towns;

class   T_path
{
    //-------------------------------------------------------------------------
    T_matr      dist_matr_;

    T_path_val  path_cur_;
    T_dist      path_cur_len_;

    T_path_val  shortest_path_;
    T_dist      shortest_path_len_;

    T_towns     free_towns_;
    //-------------------------------------------------------------------------
public:
    //-------------------------------------------------------------------------
    T_path(T_matr  const& dist_matr)
            :
            dist_matr_(dist_matr),

            shortest_path_len_(
                    numeric_limits< T_dist >::max()
            )
    {
        for (T_town t{}; t < dist_matr.size(); ++t)
        {
            free_towns_.insert(t);
        }

        push_town_with_delta_dist(0);
    }
    //-------------------------------------------------------------------------
    void    find_and_print_shortest()
    {
        find_shortest();
        print_shortest();
    }
    //-------------------------------------------------------------------------
private:
    void    push_town_with_delta_dist
            (
                    T_town  town,
                    T_dist  delta_dist = 0
            )
    {
        path_cur_.emplace_back(town);
        free_towns_.erase(town);
        path_cur_len_ += delta_dist;
    }

    void    find_shortest()
    {
        do
        {
            if (
                    successfully_fill_better_path()
                    )
            {
                shortest_path_ = path_cur_;
                shortest_path_len_ = path_cur_len_;
            }
        } while (
                successfully_inc_back_town()
                );
    }

    bool    successfully_fill_better_path()
    {
        while (
                !path_is_full()
                && successfully_push_min_good_town()
                );

        return  path_is_full();
    }

    bool    path_is_full()
    {
        return      path_cur_.size()
                    >= dist_matr_.size() + 1;
    }

    bool    successfully_push_min_good_town()
    {
        return      path_cur_.size()
                    == dist_matr_.size()
                    ? successfully_push_good_town(0)
                    : successfully_push_good_min_free_town_not_less_than(0);
    }

    bool    successfully_push_good_town(T_town     town)
    {
        auto    delta_dist = dist_matr_[path_cur_.back()]
        [town];


        bool    bool_res = path_cur_len_
                           + delta_dist

                           < shortest_path_len_;

        if (bool_res)
        {
            push_town_with_delta_dist
                    (
                            town,
                            delta_dist
                    );
        }

        return  bool_res;
    }

    bool    successfully_push_good_min_free_town_not_less_than(T_town  town_start)
    {
        for (auto i = free_towns_.lower_bound(town_start); i != free_towns_.end(); i++)
        {
            if (successfully_push_good_town(*i))
                return true;
        }
        return false;
    }

    bool    successfully_inc_back_town()
    {
        return  path_cur_.size()
                > 1

                && (
                        successfully_push_good_min_free_town_not_less_than
                                (
                                        pop_and_get_town() + 1
                                )

                        || successfully_inc_back_town()
                );
    }

    T_town  pop_and_get_town()
    {
        auto    back_town = path_cur_.back();
        path_cur_.pop_back();

        if (back_town)
        {
            free_towns_.insert(back_town);
        }

        auto    penultimate_town = path_cur_.back();

        path_cur_len_ -= dist_matr_[penultimate_town]
        [back_town];

        return  back_town;
    }

    void    print_shortest()
    {
        cout << std::endl;

        for (auto town : shortest_path_)
        {
            cout << town + 1
                 << '\t';
        }

        cout << std::endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Rus");

    ios::sync_with_stdio(false);

    int towns_total{};
    
    do
    {
        cout << "Введите кол-во (>= 2): ";
        cin >> towns_total;
    } while (towns_total < 2);

    cout << "Введите длину : " << endl;

    T_matr dist_matr(towns_total,T_row(towns_total));

    for (T_town L{}; L < T_town(towns_total); ++L)
    {
        for (T_town R{}; R < T_town(towns_total); ++R)
        {
            if (L == R)
            {
                continue;
            }

            cout << L + 1
                 << " - "
                 << R + 1
                 << "\t: ";

            cin >> dist_matr[L][R];
        }
    }

    T_path  path(dist_matr);
    path.find_and_print_shortest();
}