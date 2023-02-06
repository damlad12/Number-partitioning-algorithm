#include "balancedGroups.h"
#include <iostream>
#include <algorithm>


Assignment balancedGroups(std::vector<int> const &birthdays) {
    //sorting in ascending order
    std::vector<int> ga; // Group A
    std::vector<int> gb; // Group B
    int diff = 0;
    int sum_b = 0;
    std::vector<int> copy;
    unsigned long class_size = birthdays.size();
    
    for(unsigned int i = 0; i < class_size  ; i++)
      {
          int c = birthdays[i];
          copy.push_back(c);
      }
    
    std::sort(copy.begin(),copy.end());
    if (copy.size() == 2)
    {
        std::vector<int>::iterator it = copy.begin();
        std::vector<int>::iterator it2 = ga.begin();
        std::vector<int>::iterator it6 = gb.begin();
        ga.insert(it2,*it);
        it++;
        gb.insert(it6,*it);
        diff = abs(copy[0]-copy[1]);
        std::cout<<"here";
        return Assignment(diff,ga,gb);
    }

    else
        {
            int sum = 0 ;
            for(unsigned int i = 0; i < (class_size - 1) ; i++)
              {
                  sum += copy[i];
              }
            if(sum <= copy[class_size - 1])
            {
                  for(unsigned int i = 0; i < class_size - 1  ; i++)
                    {
                        ga.push_back(copy[i]);
                    }
            gb.push_back(copy[class_size - 1]);
            diff = abs(sum-gb[0]);
            return Assignment(diff,ga,gb);
            }
            else{
                      gb.push_back(copy[class_size-1]);
                     //record diff
                      std::vector<int>::iterator it4;
                      for(it4 = gb.begin(); it4 != gb.end() ; it4++)
                      sum_b += *it4;
                      diff = abs(sum-sum_b);
                      std::vector<std::vector<std::vector<int> > > p_b;
                      std::vector<int>::iterator itt;
                          int i = 0;
                          int c = 0;
                          int x = 0;
                          int j = 0;
                          for(itt = copy.begin(); itt != (copy.end() - 1); itt++)
                          {
                          //if added to group b --> diff decreases
                          if (abs((sum_b + *itt) - (sum - *itt)) < diff)
                          {
     
                              int d = copy[class_size-1];
                              p_b.push_back(std::vector<std::vector<int>>());
                              p_b[x].push_back(std::vector<int>());
                              p_b[x][0].push_back(d);
                              p_b[x][0].push_back(*itt);
                              p_b[x].push_back(std::vector<int>());
                              
                     
                              c = i + 1;
                              
                              
                              for(int itg = 0; itg != ga.size() ; itg++){
                              if(itg != i)
                              p_b[x][1].push_back(ga[itg]);}
      
                              p_b[x].push_back(std::vector<int>());
                              p_b[x][2].push_back(sum_b + *itt);
                              p_b[x].push_back(std::vector<int>());
                              p_b[x][3].push_back(sum - *itt);
                              p_b[x].push_back(std::vector<int>());
                              p_b[x][4].push_back(abs((sum_b + *itt) - (sum - *itt)));
                    
                            
                              
                              int x_save = x;
                              int ww = c;
         
                              
                              for(int b = ww ; b < (copy.size() - 1) ; b++)
                              {
                                  if (abs((p_b[x_save][2][0] + copy[b]) - ( p_b[x_save][3][0] - copy[b])) < p_b[x_save][4][0])
                                  {
                                      
                                      x += 1;
                                      j = x;
                                      p_b.push_back(std::vector<std::vector<int>>());
                                      p_b[j].push_back(std::vector<int>());
                                      
                                      for(int o = 0; o < p_b[x_save ][0].size(); o++)
                                      {
                                      p_b[j][0].push_back(p_b[x_save][0][o]);
                                      }
                                      
                                     
                                      p_b[j][0].push_back(copy[b]);
                                      p_b[j].push_back(std::vector<int>());
                                      p_b[j].push_back(std::vector<int>());
                                      p_b[j][2].push_back(p_b[x_save ][2][0] + copy[b]);
                                      p_b[j].push_back(std::vector<int>());
                                      p_b[j][3].push_back(p_b[x_save ][3][0] - copy[b]);
                                      p_b[j].push_back(std::vector<int>());
                                      p_b[j][4].push_back(abs( p_b[j][2][0] - p_b[j][3][0] ));
                                      
                                      int cc = b + 1 ;
                                      int how_many = 0;
                                      int j_save = j ;
                                  
                                  
                                          for(int rr = cc ; rr < (copy.size() - 1) ; rr++)
                                          {
                                          
                                              if (abs((p_b[j_save][2][0] + copy[rr]) - ( p_b[j_save][3][0] - copy[rr])) < p_b[j_save][4][0])
                                              {
                                                  
                                                  x += 1;
                                                  j = x;
                                                  
                                                  how_many += 1;
                                                  
                                                  p_b.push_back(std::vector<std::vector<int>>());
                                                  p_b[j].push_back(std::vector<int>());
                                                  
                                                  //push_back all elements in the previous set using j_save
                                                  for(int o = 0; o < p_b[j_save ][0].size(); o++)
                                                  {
                                                  p_b[j][0].push_back(p_b[j_save][0][o]);
                                                  }
                                                  
                                                  p_b[j][0].push_back(copy[rr]);
                                                  p_b[j].push_back(std::vector<int>());
                                                  p_b[j][1].push_back(1);
                                                  p_b[j].push_back(std::vector<int>());
                                                  p_b[j][2].push_back(p_b[j_save][2][0] + copy[rr]);
                                                  p_b[j].push_back(std::vector<int>());
                                                  p_b[j][3].push_back(p_b[j_save][3][0] - copy[rr]);
                                                  p_b[j].push_back(std::vector<int>());
                                                  p_b[j][4].push_back(abs(p_b[j][2][0] - p_b[j][3][0]));
                                                  j_save += 1;
                                                  
                                              }
                                                
                                      
                                              
                                          }
                                         
                                    
                                  }
                                 
                              }
                             x += 1;
                             
                          }
                        i++;
                          }
                    
            
                  
                      //find G1 and G2 corresponding to the smallest difference of sums
                      std::vector<std::vector<std::vector<int> > >::iterator u;
                      int min_index = 0;
                      int min_diff = p_b[0][4][0];
                      int a = 1;
                      for (u = (p_b.begin() + 1) ; u != p_b.end(); u++) {
                           if (p_b[a][4][0] < min_diff)
                           {
                               min_index = a;
                               min_diff = p_b[a][4][0];
                           }
                          a++;
                      
                       }
                
                //delete !!!!
                //    std::cout << "diff: "<< p_b[min_index][4][0]<<std::endl;
               //     std::cout <<"gb: ";
               //     for (int q = 0; q < p_b[min_index][0].size(); q++)
              //        std::cout << p_b[min_index][0][q] << " ";
              //       std::cout <<std::endl;
         //       std::cout <<"sum_b: " <<p_b[min_index][2][0]<<std::endl;
         //       std::cout <<"sum_a: " <<p_b[min_index][3][0]<<std::endl;
         //
                        
                        
                        std::vector<int> cb;
                
                        for(int q = 0; q < p_b[min_index][0].size(); q++)
                            cb.push_back(p_b[min_index][0][q]);
                            

                  std::vector<int>::iterator it;
                  for (int x : cb) {
                    it = std::find(copy.begin(), copy.end(), x);
                    if (it != copy.end()) {
                    copy.erase(it);
                    //break;
                    }
                  }
                
                
               // for (int x : copy) {
              //      std::cout <<"ga: " << x << " "<<std::endl;;
              //    }
                
                      return Assignment(p_b[min_index][4][0],p_b[min_index][0],copy);
                      }
                  
        }
}
