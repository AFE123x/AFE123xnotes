# Compartmental Analysis

$\frac{dx}{dt} = \text{input rate} - \text{output rate}$

## example

Consider a large tank holding 1000 L of pure water into which a brine solution of salt begins 
to flow at a constant rate of 6 L/min. The solution inside the tank is kept well stirred and is 
fowing out of the tank at a rate of 6 L/min. If the concentration of salt in the brine entering the 
tank is 0.1 kg/L, determine when the concentration of salt in the tank will reach 0.05 kg/L (see 
Figure 3.2).

$\text{rate in} = 6 \frac{L}{min} \times 0.05\frac{kg}{L} = 0.06 \frac{kg}{min}$

$\text{rate out} = 6 \frac{L}{min} \times \frac{x(t)}{1000} \frac{kg}{L} = \frac{6 x(t)}{1000} \frac{kg}{min}$


## example 2

For the mixing problem described in Example 1, assume now that the brine leaves the tank at a 
rate of 5 L/min instead of 6 L/min, with all else being the same (see Figure 3.3). Determine the 
concentration of salt in the tank as a function of time

$rate_{in} = 6\frac{L}{min} \times 0.1 \frac{kg}{L} = 0.6$

$rate_{out} = 5 \frac{L}{min} \times \frac{x(t)}{1000 + t}$

we can calculate the difference:

$$
\frac{dx}{dt}
$$