#include "exception.h"
#include <stdio.h>

create_exception(custom_error1);
create_exception(custom_error2);

int main(int argc, char **argv){
    try {
        throw custom_error2("error indeed thrown by %s", "custom_error2");

    } catch (custom_error1 &e) {
        printf("ERROR of type 'custom_error1': %s\n", e.what());
    } catch (custom_error2 &e) {
        printf("ERROR of type 'custom_error2': %s\n", e.what());
    } catch(exception &e){
        printf("ERROR of type created by 'create_exception': %s\n", e.what());
    } catch(...){
        printf("other exception\n");
    }

    return 0;
}

