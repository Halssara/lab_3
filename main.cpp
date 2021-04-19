#include <iostream>
#include <vector>

using namespace std;

void show_histogram_text (vector <size_t> bins, size_t bin_count, const size_t MAX_size, char indent_out, char sign_out, char axis_out)
{
    size_t max_bins = bins [0];
    for (size_t i = 0; i < bin_count; i++)
    {
        if (bins [i] > max_bins)
        max_bins = bins[i];
    }

    double height;
    if (max_bins <= MAX_size)
        height = 1;
    else
    height = (static_cast < double > (MAX_size) / max_bins);
    for (size_t i = 0; i < bin_count; i++)
    {
        if (bins [i] < 10)
        {
            cout << indent_out << indent_out;
        }
        else if (bins[i] >= 10 && bins [i] < 100)
            {
                cout << indent_out;
            }
        cout << bins [i];
        cout << axis_out;
        for (size_t j = 0; j < bins [i] * height; j++)
            {
                cout << sign_out;
            }
        cout << endl;

    }
}

void find_minmax (const vector <double> numbers, double& min, double& max)
{
    max = numbers [0];
    min = numbers [0];
    for (double x : numbers)
    {
        if (x< min)
            {
                min = x;
            }
        else if (x > max)
            {
                max = x;
            }
    }
}
vector <size_t> make_histogram (const size_t number_count, const size_t bin_count, double max, double min, const vector <double> numbers)
{
    vector <size_t> bins;
    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < number_count; i++)
        {
            bool found = false;
            for (size_t j = 0; (j < bin_count - 1) && !found; j++)
            {
                auto lo = min + j * bin_size;
                auto hi = min + (j + 1) * bin_size;
                if ((lo <= numbers[i]) && (numbers[i] < hi))
                {
                    bins[j]++;
                    found = true;
                }
            }
            if (!found)
            {
                bins[bin_count - 1]++;
            }
        }
    return bins;
}
vector <double> input_numbers (size_t count)
{
    vector < double > result(count);
    for (size_t i = 0; i < count; i++)
    {
        cout << i << " simvol massiva";
        cin >> result [i];
    }
    return result;
}

int main ()
{
    size_t number_count;
    size_t bin_count;
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_size = SCREEN_WIDTH - 3 - 1;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    cerr << "Enter bin count:";
    cin >> bin_count;
    double max, min;
    find_minmax (numbers, min, max);
    cout << min << "_" << max;
    const auto bins = make_histogram (number_count, bin_count, max, min, numbers);

    char indent_out [1], sign_out [1], axis_out [1];
    cerr << "Vvedite 1 simvol otstupa" << endl;
    cin >> indent_out [0];
    cerr << "Vvedite 1 simvol dlya otobrajeniya gistogrammi" << endl;
    cin >> sign_out [0];
    cerr << "Vvedite 1 simvol dlya osi" << endl;
    cin >> axis_out [0];
    show_histogram_text (bins, bin_count, MAX_size, indent_out[0], sign_out[0], axis_out[0]);
    getchar ();
    return 0;
}
