#include"Linked_List.h"
#include <map>
using namespace  std;
void remove_duplicate(node* head)
{
    std::map<std::int, int> mmap;

}
int main()
{
    Linked_list l;
    l.Add_node(11);
    l.Add_node(23);
    l.Add_node(11);
    l.Add_node(23);
    l.Add_node(45);
    l.Add_node(33);
    l.Add_node(45);
    l.Add_node(60);
    l.print_linked_list();
    remove_duplicate(l.head);
    l.print_linked_list();
}
