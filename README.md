# Color style transform

<p align="center">
   <br>
   <img src="Images/1_Demontration.jpg" width="70%" height="70%">
   <br>
</p>

# Implementation
The implementation of color style transformation is actually the extension of the famous "Histogram equalization", oftentimes having a good fundation is crucial to achieve great thins. <br>
<br>
**Mapping** <br>
The way color style transformation is implemented is by generating the mapping function for each R/G/B channel from input to reference image, once the distribution of histogram is approximately the same, so does color style:

<p align="center">
   <br>
   <img src="Images/2_Mapping_function.jpg" width="70%" height="70%">
   <br>
</p>

**Extention of histogram equalization** <br>
# 3_eq_histogram_forward

<p align="center">
   <br>
   <img src="Images/3_eq_histogram_forward.jpg" width="70%" height="70%">
   <br>
</p>

# 4_eq_histogram_inverse

<p align="center">
   <br>
   <img src="Images/4_eq_histogram_inverse.jpg" width="70%" height="70%">
   <br>
</p>

# 5_eq_histogram_combine

<p align="center">
   <br>
   <img src="Images/5_eq_histogram_combine.jpg" width="70%" height="70%">
   <br>
</p>

# 6_eq_histogram_combine_graph

<p align="center">
   <br>
   <img src="Images/6_eq_histogram_combine_graph.jpg" width="70%" height="70%">
   <br>
</p>


