#include <stdio.h>
#include <math.h>

float mse(float actual[], float predicted[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        float res = pow(actual[i] - predicted[i],2);
        sum += res;
    }
    return sum/n;
}

float mae(float actual[], float predicted[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        float res = fabs(actual[i] - predicted[i]);
        sum += res;
    }
    return sum/n;
}

float rmse(float actual[], float predicted[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        float res = actual[i] - predicted[i];
        res = pow(res, 2);
        sum += res;
    }
    sum = sum /n;
    sum = sqrt(sum);
    return sum;
}

float mape(float actual[], float predicted[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        float res = fabs(actual[i] - predicted[i]);
        res = res / fabs(actual[i]);
        sum += res;
    }
    return sum/n * 100;
}

int main() {
    int n;
    scanf("%d", &n);

    float actual[n], predicted[n];
    for(int i = 0; i < n; i++) {
        scanf("%f", &actual[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%f", &predicted[i]);
    }

    float mse1 = mse(actual, predicted, n);
    float mae1 = mae(actual, predicted, n);
    float rmse1 = rmse(actual, predicted, n);
    float mape1 = mape(actual, predicted, n);

    printf("MSE: %.2f, MAE: %.2f, RMSE: %.2f, MAPE: %.2f", mse1, mae1, rmse1, mape1);
}