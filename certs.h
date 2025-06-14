#ifndef CERTS_H
#define CERTS_H

// Root CA-certifikat
const char* aws_root_ca = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----)EOF";

// Enhetscertifikat
const char* device_cert = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUQrk71ZJEvOApMLOTDoKyfaT3ERQwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI1MDYwOTA5MzAx
M1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAMub1G0FesMFTll31H9z
N2+Mw+uxJxccvPX6iKouxvxjXXffIzeWqR3UTHrcRSX0wGT0XME+dH5tXmGYDIK/
8BdFtSDi0N6Li9abImPki0upBsF600TYtF9QF+K6mWF2vKqJeUvEDKnweFn/ogCj
PNfIboR/9paD0kVo2DxQhaBl3YTEw3tWP+dfAdqafPazn/94bm6ZzSyH0vZWmlwN
yBOWqTvHEa41zvULo+pgQUZAcg9S/SIpYyUdAH9dR5YPafrF+Ff/KermwRfVGg3A
450ZoIHrSyIjefsyGvubGQRYQd9vuTv4sVGPXNYcMMWCNGhqYLrHQ/3DuDUKCWc5
H+0CAwEAAaNgMF4wHwYDVR0jBBgwFoAUxKEFweDhVohvt4cUB36V8h44ZU8wHQYD
VR0OBBYEFFY3DWAk39kE/6rLMErUgEPgQnjGMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCVwOjPPM8Oa48TXXiHhdbsYBi3
ba7kj/ZJHc6uFGeOW79I1QJMMWVH+7FgoRJYQkAcnVbuTUPLfuDJ75OCFde4lPN4
a5qZ1xuj0p4mWHITpr4HYCWHtBxekASBdd8ZqHDKCLasjrbmKXgqk/xsU6e6pokg
x1UxT9xyvHq0h6iUtOcDxYr94H8SvmtZQtpSC1A2PzxlEnc+qhS/OOUXpoKp0PKY
bg2a1chOgT5tkutpYeW7AO7uf1LTh+fKIJI8xrK/l7RG7QNj62i0jiwD5cAN4nQZ
ZKiOP3jM3/eEYNq5vxOqFtI+HMohqvHE4JSMhMrkazZCX2zVGyGj5NN9vZdr
-----END CERTIFICATE-----)EOF";

// Enhetsprivat nyckel
const char* private_key = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAy5vUbQV6wwVOWXfUf3M3b4zD67EnFxy89fqIqi7G/GNdd98j
N5apHdRMetxFJfTAZPRcwT50fm1eYZgMgr/wF0W1IOLQ3ouL1psiY+SLS6kGwXrT
RNi0X1AX4rqZYXa8qol5S8QMqfB4Wf+iAKM818huhH/2loPSRWjYPFCFoGXdhMTD
e1Y/518B2pp89rOf/3hubpnNLIfS9laaXA3IE5apO8cRrjXO9Quj6mBBRkByD1L9
IiljJR0Af11Hlg9p+sX4V/8p6ubBF9UaDcDjnRmggetLIiN5+zIa+5sZBFhB32+5
O/ixUY9c1hwwxYI0aGpgusdD/cO4NQoJZzkf7QIDAQABAoIBAAl5xRcVzDLLSmwr
gX409H2ChZOweOtAcSLZeAbDioswbKcpgVAS+Ofke3K0UZuEmneYT8DGkVFY8a2F
D//9wsSyf816ANJ6mBVyvtT7S+hHg4L5nl9z3mEZLyNkH8NDbWBaaYS3KQe3o0I8
/WMeNbStJUeRVP6IP/7u9DFKZg2i2rIBwvQS99oG8t8HQSRZaQMupGnJQxAMnat+
Cc5nFBtfeEeI6d+KvU/vDdKDF8Atu/DGqB9JE1uTstb4uBQG0ztzBQeqsLzf78s3
YQztkVOGeqQxQSo2iIuBjUY/7Di9pjRMFTfMztnz+rHhuvDVPB0iajmhpPfvmpWK
HbAPTFkCgYEA9B/l+Wt0JnbdQEtwYsAMOLh80vAvSNY8GmKGN3LNMxXwtbGL26/X
GiH8Gz3DaVwGN3lMYV9lgA2QmXm5VRlPIekZMnDYZy6ctlnPd7jnGsNg1kf9Zrq+
a0Jm9iGhu0H1fMat54yWatipVvML5Z2dX5LdymKi7oCvtPAX6eZAEUsCgYEA1YNi
UWDNdS4hqOJqt7UuQXUCBTcZXXMHQQuyZY9eQIPPnKrdlvvM7KsTwEZ4usRVE+7y
OI4fJ1wePthaVSGwu181i8NAPifWKAXFfF4IGFQdVFN0PcE629qx5erUD08SHRCB
5titbQSp3x71B6ASv3vc4eGjMUOedf7ivnX6iKcCgYEAs1E28NWwFIzdCdwf6jld
ANDqx1qrsNnEfjD+m34VIkAsdpm6vJzV6JksAKqGfj6dRmQv6ZpUCRJts35I1yxn
BuacnoNrQadobz1a+nr0LqFy4RMyHCJxuoGk9YhQrybM9mFN3jZTSpppELgodfon
XcuYZI+9VGlsJwDw39tEFi8CgYEAkZlVq27azMTXmUZFRd9cmrCC3zGSr4IoeTfT
wKQCvvXj1s9B6prtRJrpDh5AaARIjB5OuThZkEqmKW76MsGVtkCX0CYmofwicwp0
gHnTBVwe4AlE5HPnglNhKwt27rWaAY3nN5ectBIRESEYMMn83u1FVBe9ZHPbFFXr
I7xqS1MCgYAEkX691BVBi9qQBX+cQv/ifk9RpkRP6UD0R3uSxg2kXLdlX8XDXtVV
wLKdrdsvVuZvsyjRZcgPnsVhW+q2Kf6+9mbhRO74mUzPTLOj55fp+CW/Sp+oGLI+
GVTIqEcMV4/vmDqnm5zRwuth5+cnbebCGxprM6kGkcMFB7+iswX4iQ==
-----END RSA PRIVATE KEY-----)EOF";

#endif
