**Acknowledgment**

In today&#39;s competitive world, there is a race for existence in which those who have the will to come forward succeed. The project is a bridge between theoretical and practical work. We have been immeasurably enriched to be working under the supervision of Daya Sagar Baral sir for providing us with the opportunity to do this project and giving all the guidance required to ignite this project. We are extremely grateful to him for providing us with nice support and guidance. We are highly indebted to our teacher Ganesh Gautam for his guidance on the basics of programming. Although the exact contents of his teachings may not be applied to this project, the fundamental concepts learned during his lectures and classes were essential for completing this project. At times, our studies carried out quite a burden to our parents, friends and our classmates, hence we would like to thank them for their understanding and support. We are also extremely thankful to the Pulchowk campus for providing us with the opportunity to do this project. We are extremely privileged to have access to a massive source of documentation and tutorial on the internet. Google and YouTube were extremely valuable sources of guidance for providing a direction to this project. They have enabled us to broaden the horizon of the limits of our ideas. Without the internet, we could not imagine transforming our software idea into a reality. Last but not the least, we would like to thank everyone who is involved in the project directly or indirectly.

---

**Abstract**

---


**Table of Contents**

---


**Objectives**

The main objectives of this project are: - To implement the object-oriented methodology and make its concept clear, - To explore the features of C++ language, - To be able to use header files to increase the reusability of our code. - To be familiar with using external libraries and learn to build graphics software using libraries such as SFML, - To build an attractive UI for the users to help them interact easily with our software.

---


**Introduction**

Set-Bud-Get is a simple software to track the budget and expenses of a user to help them manage their finance and prevent them from making financial mistakes. It is a cross-platform software for users using either Windows or Linux.

A user can plan his budget while tracking his/her expenses and income. We will also provide information about their expense pattern in the form of bar diagrams and pie charts. Users can log in to their respective accounts and add, edit, delete their entries. We are also including a feature for users to see the rate of foreign currencies and convert from one currency to another.

Only authorized users can access the software as they will be required to log in with a password to access the data within it. Users can choose not to add a password if they so desire. The data [Password] will be encrypted, such that no unauthorized users can access the software.

We have provided a nice UI for the user so that they can easily navigate through our app. Users will be able to see their monthly expenses in a pie chart according to their expense category and their yearly expense in the form of a bar diagram to compare their monthly expenses. Users can easily view their financial budget reports in form of CSV files format. Users are also able to choose the currency they desire while registering and exporting their transactions.

We have also implemented a backup and restore function that backs up the data and restores the data from the server. The server needs to run the server binary and have a port available for the client to have a TCP connection with. With this, users will then be able to back up their data to a server device and the client would be able to restore using that data.

---


**Application**

Accountancy is a huge industry. Be it managing personal accounts such as in your home, or be it for a large institution or business, being able to keep a record of each expense and income is essential. This has been done via the help of pens and paper, which has huge limitations. They are expensive to maintain, hard to store, susceptible to wear and tear, and such. This software allows its user to keep track of the cash flow, such that you can view it via a graph, and it can even be exported to a format compatible with popular software such as MS Excel.

Initially, Set-Bud-Get software is going to have limited scope. Since currently we have stored data in the disk itself and are reading it from the file store in the disk, if there is a hardware error user&#39;s data will be lost. This is negated by uploading the user&#39;s data to the server which is possible throughout the client and server applications. Internet connectivity is used to be able to back up the data. And with the implementation, we made sure that our users can access their data from any device or platform, such that when the user&#39;s login with their account, users will be able to access their data, which would be restored or synced from the server.

The software can also be further expanded such that multiple users can simultaneously edit the same data. Hence, it would be more useful for larger institutions. Although initially this project will have limited scope, however, the prime aspect of this project will be education thus, it is a good initial step.

---


**Literature survey**

---


**Methodology**

This project is going to be implemented in C++ 98 standard, using the Simple and Fast Multimedia Library for GUI purposes. CLion is the IDE that is going to be used. For the version control system, git will be used to manage and track the changes to the codebase. The code repository will be stored in GitHub, via which the team will collaborate. This project is intended to run in multiple operating systems, i.e., Windows and Linux, hence the two binaries will be made, each for its respective platform. The project has been divided into small modules, where each team member will handle his or her module, although all team members understand the entire codebase. The main module that handles the data storage is planned to be implemented initially. The data interaction will be handled through the class, where there will be a member function that will filter and retrieve the data from the storage.

---


**Implementation**

---


**Description**

The main purpose of our program is to track the budget of the user. A user will be able to sign up for an account and sign in through the login screen. After login, the user will be teleported to a dashboard which is the homepage of the program. A sidebar is present on the left side of the screen that contains several tabs namely Dashboard, Add Expense, Add Income, See Report, Forex, Backup, and Logout.

Firstly, the user must set his budget amount for a month through the Add Income tab. The user can add expenses through the &#39;Add Expense&#39; Tab. Users can add expenses and incomes. Such individual transactions can be added by the user manually.

Our app also has a currency converting feature. It can be accessed through the &#39;forex&#39; tab. Users can convert a sum of money from one currency to another. On the same page, we have listed the top currency exchanges rates in form of a table. One of the best features of this app is that you can see the report of your budget, expense, and saving in graphical form from the &#39;see report&#39; tab. There you can switch between monthly reports and yearly reports. In the monthly report, you can see the percentage of your different expenses and savings of a month in the form of a pie chart. In the yearly, report, you can see your expense report and your savings report in form of the bar graph. The dashboard page which is also the homepage of the program can be accessed through the &#39;dashboard&#39; tab from the sidebar. Here, a user can see his recent transactions, along with a pie chart and bar graph representing the current state of total expense in different fields compared to the total capital available.

Users can also back it up to a server and restore their data from it if the server is running the set-bud-get server application.

Thus, this program simply keeps track of the budget enabling the user to add and append expenses and see reports based on the user&#39;s monthly and yearly financial transactions accompanied by additional features like a currency converter, back up to and restore from the server.

---


**Block Diagram**

![SetBudGet-Client Server Communication](https://user-images.githubusercontent.com/69170305/130853944-83872acc-61a4-4b44-8a92-337348a84168.png)

---

![SetBudGet-Flow-chart app](https://user-images.githubusercontent.com/69170305/130853971-581351cc-ef55-4049-9f29-53fa8b0596e8.png)

---


**Results**

---


**Screenshots**

---


**Login Screen:**


**Login Screen (Wrong authentication)**

![](RackMultipart20210825-4-72pd0z_html_737bdb639535e6b5.png)

---


**Signup Page**

![](RackMultipart20210825-4-72pd0z_html_f23d846c6711b6aa.png)

**Signup Page (Invalid username):**

![](RackMultipart20210825-4-72pd0z_html_a556a9e4edbdfa07.png)

---


**Adding Expense:**

![](RackMultipart20210825-4-72pd0z_html_85e08b840dba493.png)

**Adding Income:**

![](RackMultipart20210825-4-72pd0z_html_c7281f6a5f21f54d.png)

---


**Dashboard Page:**

![](RackMultipart20210825-4-72pd0z_html_32ab1ae4077ecfba.png)

**Forex Page:**

![](RackMultipart20210825-4-72pd0z_html_f4c9fa1495b54e0a.png)

---


**See Report [Monthly]**
 ![](RackMultipart20210825-4-72pd0z_html_1fe782f15bf1cf32.png)

**See Report [Yearly]:**

![](RackMultipart20210825-4-72pd0z_html_6fc8d11fd0d3987a.png)

---


**Problems Faced and solutions**

There are no tasks free from challenges. The first problem is the situation we are in because of the COVID crisis in a state of fear and partial lockout. Due to the current situation, we could only communicate online and there were times when we had difficulties communicating due to sudden power cuts, internet issues, and much more.

On top of that, we were also facing compiler issues because we were working in different Operating Systems. However, we passed the ups and downs to the completion of the project. Asking questions and discussions with friends helped us a lot during the project. A summary of the problems we experienced in the course of our development is provided below:

1. Since we were using C++ 98 there were less sturdy material and compatibility issues with different libraries and frameworks.
2. Installing SFML was also very confusing because there was no proper documentation for building SFML locally and the only documentation we were able to access was about installing SFML in Codeblocks only.
3. Lack of SFML developer community since the usage of SFML has drastically decreased due to the availability of new and better frameworks.
4. Adding Networking features was harder than we had thought because we had to write the logic in C++ since using another language would have been much easier. Multi-threaded networking was a lot harder and complex so we had to settle down to one connection at a time.
5. Our ISP had blocked port forwarding so we were not able to back up our data to the actual server so we had to settle down to using another computer in our local network as a server.
6. There were many merge conflicts while we were all working in the same file and while pushing the code to GitHub repositories we would edit the CmakeList file and that simple edit was confusing for us during the early days of development.

We were able to overcome the hurdles we experienced while developing this software. We scouted every search result of google and StackOverflow for solving our problems and even came up with solutions ourselves. We solved the problem we faced while installing SFML by watching different tutorials and visiting different websites. Merge conflicts were unavoidable but we tackled them by merging code only when all 3 of us were in a group call in Telegram or Discord.

Our journey was filled with ups and downs but we kept our cool and completed this project successfully.

---


**Limitations and future enhancements**

As we know a system can never reach perfection, Our program by any means is not free of bugs and loopholes but we have tried our best to minimize it. There are a lot of shortcomings in our projects like not being able to connect to 2 users at the same time, slow startup, simple encryption of passwords, and a lot more. The following points summarize the project&#39;s limitations and likely improvements:

-

---


**Conclusion and recommendations**

---


**References**

- Daya Sagar Baral and Diwakar Baral, &quot;The Secrets of Object-oriented Programming&quot;, Bhundipuran Prakasan
- [https://www.sfml-dev.org/tutorials/2.5](https://www.sfml-dev.org/tutorials/2.5)
- [https://en.cppreference.com/w/](https://en.cppreference.com/w/)
- SFMl 2.4 for beginners [https://www.youtube.com/playlist?list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY\_SLRW9](https://www.youtube.com/playlist?list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY_SLRW9)
- [C++/SFML] Textbox and Button Classes [https://termspar.wordpress.com/2019/04/11/c-sfml-textbox-and-button-classes/](https://termspar.wordpress.com/2019/04/11/c-sfml-textbox-and-button-classes/)
- [https://www.stackoverflow.com](https://www.stackoverflow.com/)
- [https://www.cplusplus.com](https://www.cpluspl
