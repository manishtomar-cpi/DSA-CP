  //when garbage when 0
    int arr1[10];
     for (auto &i : arr1) //all garbage
    {
        cout << i << " ";
    }

     int arr2[10] ={1,4,6}; // 1,4,6,0,0.... -> because define some values
     for (auto &i : arr2) //all garbage
    {
        cout << i << " ";
    }

    // int arr[]; //give error have to define size

    int arr3[10];
    cout << sizeof(arr3)<< endl;