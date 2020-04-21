#!/usr/bin/env python
# coding: utf-8

# In[25]:


import random 
import time 
from numpy.random import seed 
from numpy.random import randint 
import matplotlib.pyplot as plt 


# In[26]:


def power(x, y, p):  
    res = 1;  
    x = x % p; 
    while (y > 0): 
        if (y & 1): 
            res = (res * x) % p; 

        y = y>>1; 
        x = (x * x) % p; 

    return res; 


# In[27]:


def miillerTest(d, n): 
 
    a = 2 + random.randint(1, n - 4); 
    #elements.append(a) 
    x = power(a, d, n); 

    if (x == 1 or x == n - 1): 
        return True; 

    while (d != n - 1): 
        x = (x * x) % n; 
        d *= 2; 
    #print(d)
        if (x == 1): 
            return False; 
        if (x == n - 1): 
            return True;  
    return False; 


# In[28]:


def Check_Prime( n, k): 

    if (n <= 1 or n == 4): 
        return False; 
    if (n <= 3): 
        return True; 
    d = n - 1; 
    while (d % 2 == 0): 
        d = d//2; 

    for i in range(k): 
        if (miillerTest(d, n) == False): 
            return False; 

    return True; 


# In[29]:


elements = []
times =[]
for k in range(2,8):
    start = time.clock()
    for n in range(2,1000): 
        if (Check_Prime(n, k)): 
              print(n , end=" ")
       
    end = time.clock() 
            
    elements.append(k) 
    times.append(end-start)


# In[30]:


plt.xlabel('k-value') 
plt.ylabel('Time') 
plt.plot(elements, times, label ='Numbers b/w 2-1000') 
plt.legend() 
plt.show()


# In[31]:


elements = []
times =[]
for k in range(2,8):
    start = time.clock()
    for n in range(2,10000): 
        if (Check_Prime(n, k)): 
              print(n , end=" ")
       
    end = time.clock() 
            
    elements.append(k) 
    times.append(end-start)


# In[32]:


plt.xlabel('k-value') 
plt.ylabel('Time') 
plt.plot(elements, times, label ='Numbers b/w 2-10000') 
plt.legend() 
plt.show()


# In[33]:


elements = []
times =[]
for k in range(2,8):
    start = time.clock()
    for n in range(2,100000): 
        if (Check_Prime(n, k)): 
              print(n , end=" ")
       
    end = time.clock() 
            
    elements.append(k) 
    times.append(end-start)


# In[34]:


plt.xlabel('k-value') 
plt.ylabel('Time') 
plt.plot(elements, times, label ='Numbers b/w 2-100000') 
#plt.grid() 
plt.legend() 
plt.show()


# In[35]:


elements = []
times =[]
for k in range(2,8):
    start = time.clock()
    for n in range(100000,500000): 
        if (Check_Prime(n, k)): 
              print(n , end=" ")
       
    end = time.clock() 
            
    elements.append(k) 
    times.append(end-start)


# In[36]:


plt.xlabel('k-value') 
plt.ylabel('Time') 
plt.plot(elements, times, label ='Numbers b/w 100000-500000') 
 
plt.legend() 
plt.show()


# In[ ]:




