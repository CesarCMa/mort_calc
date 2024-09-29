# Mortgage CLI Calculator

`mort_calc` is a simple tool to calculate monthly payments of your mortgage based on: house price, down payment, loan term and interest rate.

## Usage

After compiling the tool with `make compile` you can run it with the command `./bin/mort_calc` and required parameters:

* `-p <price>`: House price (without taxes!).
* `-d <down payment>`: Amount of money you will pay upfront. Note: normally banks require you to pay, at least, 20% of the house value.
* `-t <loan term>`: Amount of time over which the loan must be repaid, in years.
* `-i <interest>`: Interest rate of the loan.