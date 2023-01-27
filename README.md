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
The way color style transformation is implemented is by generating the mapping function for each R/G/B channel from input to reference image automatically, once the distribution of histogram is approximately the same, so does color style:

<p align="center">
   <br>
   <img src="Images/2_Mapping_function.jpg" width="70%" height="70%">
   <br>
</p>

**Extention of histogram equalization** <br>
The purpose of histogram equalization is to have the histogram uniformly distributed to increase the contrast of the image, although the bit depth for pixel intensity is discrete, the transformation is approximately uniform but is enough for the application, so the first step is to transform both the input and reference images to have approximately the same histogram distribution:

<p align="center">
   <br>
   <img src="Images/3_eq_histogram_forward.jpg" width="70%" height="70%">
   <br>
</p>

**Inverse mapping** <br>
Once we have the forward mapping from reference image to histogram equalized image, then we can approximate the inverse mapping too, one trick here is to rememorize the fact the function inverse is actually the 45 degree mirror image of forward mapping:

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


