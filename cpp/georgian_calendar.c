
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
  return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

void add_days_to_date(const int num_days_to_add, int* day, int* month, int* year) {
  int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  days_in_month[1] = is_leap_year(*year)? 29 : 28;

  // printf("%d is %s leap year.\n", *year, is_leap_year(*year)? "a" : "not a");

  for (int i = 0; i < num_days_to_add; i++) {
    if (*day < days_in_month[(*month) - 1]) {
      (*day)++;
    } else {
      (*day) = 1;
      if ((*month) < 12) {
        (*month)++;
      } else {  // month == 12
        (*month) = 1;
        (*year)++;
        days_in_month[1] = is_leap_year(*year)? 29 : 28;
      }
    }
  }
}

int main() {
  int day = 1;
  int month = 1;
  int year = 2000;
  int days_from_now = 365;

  // Read the date in the format "dd/mm/yyyy"
  printf("Enter the date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &day, &month, &year);
  printf("Date: %d/%d/%d\n", day, month, year);

  // how many days from now?
  printf("How many days from now? ");
  scanf("%d", &days_from_now);
  add_days_to_date(days_from_now, &day, &month, &year);

  printf("New date %d days from now: %d/%d/%d\n", days_from_now, day, month, year);
  return 0;
}
