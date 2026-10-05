int maxArea(int* height, int heightSize) {
    if(height == NULL) {
        return 0;
    }
    if(heightSize <= 1) {
        return 0;
    }

    int h1 = 0;
    int h2 = heightSize - 1;
    int maxArea = 0;

    while (h1 < h2) {
        int h = *(height + h1) < *(height + h2) ? *(height + h1) : *(height + h2);

        int area = h * (h2 - h1);

        if(area > maxArea) {
            maxArea = area;
        }

        if(*(height + h1) < *(height + h2)) {
            h1++;
        }
        else {
            h2--;
        }
    }

    return maxArea;
}