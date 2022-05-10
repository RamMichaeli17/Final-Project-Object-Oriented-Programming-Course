<div id="top"></div>

<!-- PROJECT SHIELDS -->
[![GitHub repo size][reposize-shield]](#)
[![GitHub language count][languagescount-shield]](#)
[![Contributors][contributors-shield]][contributors-url]
[![Stargazers][stars-shield]][stars-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
[![Gmail][gmail-shield]][gmail-url]






<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course">
    <img src="https://user-images.githubusercontent.com/62435713/163417485-c92a844d-484e-4dac-8622-9c19c380f3ea.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Final Project Object Oriented Programming: "Just Draw It"</h3>

  <p align="center">
    The project is a paint program that stores the figures in an array and prints them to the screen , every figure has its own attributes. There are functions that can be used on the figures to change their size , move them , delete them , and so on , and there's also mathematical functions that prints area and perimeter. There is also an option to "undo" and "redo" drawn shapes. The shapes can be saved to and loaded from a file.
    <br />
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#build-requirements">Build Requirements</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contributors">Contributors</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About The Project

![image](https://user-images.githubusercontent.com/62435713/163430728-4fa4b9df-8258-4a60-9316-f123597b8d16.png)

This is my first OOP project in C++. <br>
In this project you may find several subjects such as: <br>
1. Class Members. Instance and Static Members. Use of Accessibility Modifiers. Fields. Data abstraction and information hiding, separating interface from implementation, implementing Abstract Data Types with classes, constructors, destructors. <br>
2. Composition. Friend functions and friend classes. The "this" pointer. Static class members. Const. <br>
3. Operator Overloading. Class members vs. friend functions. Unary and binary operators. Operators new and delete. <br>
4. Inheritance. Base and derived classes, protected members, indirect base classes, composition vs. inheritance. Multiple inheritance. <br>
5. Abstract and concrete classes. Polymorphism. Dynamic binding. <br>
6. STL. Data Structures and Algorithms in C++ and STL. <br>
7. Windows Programming in C++. File I/O and Serialization. <br>
8. MFC - Microsoft foundation classes: Microsoft foundation classes (MFC) are C++ language and Windows application programming interface (API) classes bundled in a software application development library. The MFC library is a collection of many different classes, including Windows APIs. <br>


<p align="right">(<a href="#top">back to top</a>)</p>


## Build Requirements

### Visual Studio 2017

 * *Community*, *Professional* or *Enterprise* Edition
 * VC++ 2017 latest v141 tools
 * Visual C++ compilers and libraries for (ARM, ARM64)
 * Windows XP support for C++
 * Visual C++ MFC for (x86 and x64, ARM, ARM64)
 * Visual C++ ATL for (x86 and x64, ARM, ARM64)
 * Windows 10 SDK

### Visual Studio 2019

 * *Community*, *Professional* or *Enterprise* Edition
 * MSVC v142 - VS 2019 C++ (x64/x86, ARM, ARM64) build tools (Latest)
 * C++ MFC for latest v142 build tools (x86 & x64, ARM, ARM64)
 * C++ ATL for latest v142 build tools (x86 & x64, ARM, ARM64)
 * Windows 10 SDK

### Visual Studio 2022

 * *Community*, *Professional* or *Enterprise* Edition
 * MSVC v143 Buildtools (x64/x86, ARM, ARM64)
 * C++ MFC for latest v143 build tools (x64/x86, ARM, ARM64)
 * C++ ATL for latest v143 build tools (x64/x86, ARM, ARM64)
 * Windows 10 SDK

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Follow these simple steps:

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course.git
   ```
2. Run the program
   ```sh
   press ctrl+F5 or press the "start without debugging" button
   ```
   ![image](https://user-images.githubusercontent.com/62435713/163438214-17503747-8f87-455f-a416-ecd3b2ee6215.png)


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

1. Create a shape (rectangle, square, circle, ellipse, straight line) which is stored in an array of shapes.
2. Option to choose whether the shape will have a thick or thin frame.
3. Option to choose what color the shape will be, and also what color the frame will be (CPen, CBrush).
4. Option to enter a sample name "X" and receive output "Hello X".
5. Option to choose the color of the name.
6. A button that calculates the perimeter of a shape (by clicking on the button and then clicking on a specific shape)
7. A button that calculates the area of a shape in the same way.
8. A tool that displays a current date.
9. Clear button, which deletes all shapes in the array by calling the RemoveAll function.
10. Resize button, which resizes a shape by clicking the button, then clicking the shape and dragging the mouse.
11. Delete Shape button, which deletes a specific shape by clicking on the button and then clicking on a shape we want to delete.
12. Move Shape button, which moves an existing shape by pressing the button and then dragging the shape.
13. Draw button, which switches to "drawing" mode by clicking on it.
14. Undo button, which transfers the last drawn shape to another array (not printed to the screen) thus effectively deleting the last action we did.
15. Redo button, which returns the shapes stored in an unprinted array to the screen to an array that prints, one after the other.
16. Save button, which with the help of serialization saves the array of shapes (including all its properties) in a "fig" file in a particular path on the computer.
17. Load button, which works in the same way only this time reads the data from the file.

![Just Draw It - Demo Gif](https://user-images.githubusercontent.com/62435713/163828413-84c34e27-7f05-46ca-a0d5-e2bbf70987fa.gif)



_For more examples, please refer to the [Documentation](https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course/raw/main/Project%20Appendices.rar)_

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See [`LICENSE.txt`](https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course/blob/main/LICENSE.txt) for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



## Contributors

We thank the following people who contributed to this project:


<table>
  <tr>
    <td align="center">
      <a href="https://github.com/RamMichaeli17">
        <img src="https://avatars.githubusercontent.com/u/62435713?v=4" width="100px;"/><br>
        <sub>
          <b>Ram Michaeli</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Gal1997">
        <img src="https://avatars.githubusercontent.com/u/66265894?v=4" width="100px;"/><br>
        <sub>
          <b>Gal Israeli</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

<p align="right">(<a href="#top">back to top</a>)</p>




<!-- CONTACT -->
## Contact

Ram Michaeli - ram153486@gmail.com

Project Link: [https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course](https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course)

<a href="mailto:ram153486@gmail.com"><img src="https://img.shields.io/twitter/url?label=Gmail%3A%20ram153486%40gmail.com&logo=gmail&style=social&url=https%3A%2F%2Fmailto%3Aram153486%40gmail.com"/></a>
<a href="https://linkedin.com/in/ram-michaeli"><img src="https://img.shields.io/twitter/url?label=ram%20Michaeli&logo=linkedin&style=social&url=https%3A%2F%2Fmailto%3Aram153486%40gmail.com"/></a>
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
[reposize-shield]: https://img.shields.io/github/repo-size/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course?style=for-the-badge

[languagescount-shield]: https://img.shields.io/github/languages/count/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course?style=for-the-badge

[contributors-shield]: https://img.shields.io/github/contributors/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course.svg?style=for-the-badge

[contributors-url]: https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course/graphs/contributors

[stars-shield]: https://img.shields.io/github/stars/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course.svg?style=for-the-badge

[stars-url]: https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course/stargazers

[license-shield]: https://img.shields.io/github/license/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course.svg?style=for-the-badge

[license-url]: https://github.com/RamMichaeli17/Final-Project-Object-Oriented-Programming-Course/blob/master/LICENSE.txt

[linkedin-shield]: https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white

[linkedin-url]: https://linkedin.com/in/ram-michaeli

[gmail-shield]: https://img.shields.io/badge/ram153486@gmail.com-D14836?style=for-the-badge&logo=gmail&logoColor=white

[gmail-url]: mailto:ram153486@gmail.com

[product-screenshot]: images/screenshot.png
