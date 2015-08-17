# Module 1: Introduction to Parallel Programming Part 1

## Moore's Law

Gordan Moore authored the article "Cramming More Components onto Integrated
Circuits" Electronics Magazine. 19 April 1965. He made his research based on
several data points.

He forcasted that the number of transistors added to a chip would approximately
double every 24 months. And to this day, it holds up fairly well.

## Programming Mentality 

What this gives is greater and greater performance in computing every 24 years.
Psychologically, this makes people believe that if you wait long enough, the
hardware will get good enough to better your programs. 

This, however, comes at a price because of the increased power consumption of
those higher density transistor chips. The increase in power consumption is
nearly quadratic (1.74). This is the "power wall" people talk about.

Eventually engineers created simple lower power cores that can be used in
today's mobile devices. Thus, people were not optimizing power and not
performance.

## Parallel Computing

Performance now is governed by software, not just hardware. There is "no free
lunch" anymore for performance by just waiting on hardware.

Additionally, there is no automatic parallization of your code. This process is
still very manual.

References:

- Chandrakasan, A.P.; Potkonjak, M.; Mehra, R.; Rabaey J.; Brodersen, R.W.,
  "Optimizing power using transformations," *IEEE Transactions on Computer-Aided
  Design of Integrated Circuits and Systems, Vol 14, No 1, pp. 12-31, Jan 1995.
