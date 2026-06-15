
void kernel_main()
{
    char* video = (char*)0xB8000;

    char text[] = "NechiOS";

    int i = 0;
    
    while (text[i])
    {
        video[i*2] = text[i];
        video[i*2+1] = 0x07;

        i++;
    }

    while (1)
    {
        
    }
}