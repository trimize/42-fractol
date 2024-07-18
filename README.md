# fractol


Graphical project to render fractals.
This project uses minilibx to draw the pixels, it is advised to use it on linux.

## Installation


```bash
git clone https://github.com/trimize/42-fractol.git && cd 42-fractol
```

## Usage

To create the sorting executable :

```bash
make
```

This will show a menu on the differents way to use the executable : 

![Alt text](./assets/menu_make.png?raw=true)

To run the algorithm :

The numbers can be either in between double quotes separated by a space or just their own argument.
Accepted numbers are between int MIN and int MAX and no duplicates.

Below is an example :

```bash
./push_swap "1 2 3 4" 5 6 7 8 9 "52 65 89" 105
```

To run the checker : 

```bash
./push_swap "1 2 3 4" 5 6 7 8 9 "52 65 89" 105 | ./checker
```


## Grade

125
