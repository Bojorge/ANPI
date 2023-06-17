function result = romberg(f, a, b, n)
    % Romberg method for numerical integration
    % Inputs:
    %   - f: Function to be integrated
    %   - a: Lower limit of integration
    %   - b: Upper limit of integration
    %   - n: Number of rows in the Romberg table
    % Output:
    %   - result: Approximation of the integral

    % Initialize the Romberg table
    R = zeros(n, n);

    % Compute the step size
    h = (b - a) ./ (2.^(0:n-1));

    % Compute the first column of the Romberg table
    R(1, 1) = (h(1) / 2) * (feval(f, a) + feval(f, b));

    % Use the trapezoidal rule for the remaining columns
    for j = 2:n
        % Compute the composite trapezoidal rule approximation
        sum_f = 0;
        for i = 1:2^(j-2)
            sum_f = sum_f + feval(f, a + (2*i-1)*h(j));
        end
        R(j, 1) = 0.5 * R(j-1, 1) + h(j) * sum_f;

        % Use Richardson extrapolation for the remaining elements
        for k = 2:j
            R(j, k) = R(j, k-1) + (R(j, k-1) - R(j-1, k-1)) / ((4^(k-1)) - 1);
        end
    end

    % Return the final approximation
    result = R(n, n);
end




f = @(x) exp(x);  % Definición de la función a integrar
a = 0;            % Límite inferior del intervalo
b = 1;            % Límite superior del intervalo
n = 4;            % Número de filas en la tabla de Romberg

approximation = romberg(f, a, b, n);  % Llamada a la función romberg

fprintf("Approximation: %.6f\n", approximation);

