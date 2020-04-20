#include <iostream>
#include <vector>

using namespace std;

const int INTERACTIVE =0;

int compute_min_refills(int tot_dist, int tank_miles, vector<int> &fuel_locations) {
    // write your code here
    //note fuel locations include the start=0 and final_stop = tot_dist stops too
    int num_fuel_stations = fuel_locations.size();
    vector<int> fuel_filled_flags(num_fuel_stations,0);

    int current_stop     = 0;
    int current_stop_idx = 0;
    int current_pit_stop = 0;
    fuel_filled_flags[0]  = 1;
    int next_max_miles = current_pit_stop + tank_miles;
    int num_pit_stops = 0;

    //if next_max_miles exceeds the destination distance , it means u can travel to the destination without having to refuel anymore
    if(next_max_miles >=fuel_locations[num_fuel_stations -1]){
      if(INTERACTIVE == 1)
      {  cout <<"DESTINATION REACHED !! Trivial case ! No refilling required, num_pit_stops ="<<num_pit_stops<<endl;
      }
      return num_pit_stops;
    }



    int previous_stop, previous_stop_idx;
    vector<int> pit_stops(num_fuel_stations);
    pit_stops[num_pit_stops] = 0;
    int loop_count = 1;
    for(int i =1; i <=num_fuel_stations; i++, loop_count++)
    { previous_stop     = current_stop;
      previous_stop_idx = i-1;
      current_stop      = fuel_locations[i];
      current_stop_idx  = i;
      if (current_stop > next_max_miles)
      {   //if fuel has not been filled in the previous stop, you can go back to that stop and fill
          if(fuel_filled_flags[previous_stop_idx] ==0)
          {      num_pit_stops++;
                 pit_stops[num_pit_stops]            = fuel_locations[previous_stop_idx];
                 fuel_filled_flags[previous_stop_idx] = 1;
                 next_max_miles                      = fuel_locations[previous_stop_idx] + tank_miles;


                 //(Because you have to iterate for the current stop again
                 current_stop_idx = previous_stop_idx ;// i.e. i-1
                 current_stop     = fuel_locations[previous_stop_idx];
                 i                = i-1; //reset i for the loop

                 if(INTERACTIVE == 1){
                    cout <<"Refuelling @ loop_count = "<<loop_count <<", i(orginal) = " << i+1 <<" , i(reset) = " <<i;
                    cout <<". Refuelling station # = "<<previous_stop_idx<<" , station_location = "<<fuel_locations[previous_stop_idx]<<" miles"<<endl;
                 }
          }
          //if fuel has already been filled in previous location, then quit
          else
          {     if(INTERACTIVE == 1){
                  cout <<"Attempted Refuelling at invalid previous station # = "<<previous_stop_idx<<" , station_location = "<<fuel_locations[previous_stop_idx]<<" miles. ";
                  cout <<"Quitting, no fuel possible @ loop_count ="<<loop_count<<", i = " << i <<endl;
                }
                return -1;
          }
      }//eof if (current_stop > next_max_miles)
      else if(current_stop == next_max_miles)
      {   //if fuel has not been filled in the previous stop, you can go back to that stop and fill
          if(fuel_filled_flags[current_stop_idx] ==0)
          {      num_pit_stops++;
                 pit_stops[num_pit_stops]           = fuel_locations[current_stop_idx];
                 fuel_filled_flags[current_stop_idx] = 1;
                 next_max_miles                     = fuel_locations[current_stop_idx] + tank_miles;

                 if(INTERACTIVE == 1){
                    cout <<"Refuelling @ loop_count = "<<loop_count <<", i = " << i ;
                    cout <<"Refuelling station # = "<<current_stop_idx<<" , station_location = "<<fuel_locations[current_stop_idx]<<" miles. "<<endl;
                 }
          }
          //if fuel has already been filled in previous location, then quit
          else
          {     if(INTERACTIVE == 1){
                  cout <<"Attempted Refuelling at invalid current station # = "<<current_stop_idx<<" , station_location = "<<fuel_locations[current_stop_idx]<<" miles. ";
                  cout <<"Quitting, no fuel possible @ loop_count ="<<loop_count<<", i = " << i <<endl;
                }
                return -1;
          }
      }//eof if (current_stop > next_max_miles)


      //Check if next_max_miles equals/exceeds the destination distance , it means u can travel to the destination without having to refuel anymore
      if(next_max_miles >=fuel_locations[num_fuel_stations -1]){
        if(INTERACTIVE == 1)
        {  cout <<"DESTINATION REACHED !! num_pit_stops ="<<num_pit_stops<<" @ loop_count ="<<loop_count<<", i = " << i <<endl;
        }
        return num_pit_stops;
      }

    }//for(int i =1; i <=num_fuel_stations; i++)
    //return num_pit_stops;
}


int main() {
    int tot_dist , tank_miles, num_fuel_stations;int previous_stop;
    cin >> tot_dist;
    cin >> tank_miles;
    cin >> num_fuel_stations;

    num_fuel_stations += 2; //add 2 more: one for the start and one for the stop
    vector<int> fuel_locations(num_fuel_stations);
    fuel_locations[0]   = 0;
    for (size_t i = 1; i <= num_fuel_stations-2; ++i)
        cin >> fuel_locations.at(i);
    fuel_locations[num_fuel_stations-1] = tot_dist;



    int min_refills = compute_min_refills(tot_dist, tank_miles, fuel_locations) ;
    if(INTERACTIVE == 1)
    {  cout <<"\n OUTPUT: min_refills = ";
    }
    cout<<min_refills<<endl;

    return 0;
}
