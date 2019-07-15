## Token Auth
### Token Auth特点
- 支持跨域访问
- 无状态：Token在服务端不需要存储session信息。
- 适用CDN：通过内容分发网络请求服务端的所有信息（HTML，图片等）
- 去耦：不需要绑定到一个特定的身份验证方案。
- 基于标准化：可以采用标准化的JSON Web Token（JWT）
### 基于JWT的Token认证
一个JWT即为一个字符串，由头部（Header）、载荷（Payload）与签名（Signature）组成。
- 头部：用于描述关于该JWT的基本信息，例如其类型以及签名所使用的算法等。
- 载荷：包含Token的具体内容，有一些为标准字段：
	- iss：lssuer（发行者）
	- sub：Subject（主题）
	- aud：Audience（观众）
	- exp：Expiration time（过期时间）
	- nbf：Not before
	- iat：lssued at（发行时间）
	- jti：JWT ID</br>
将上面的JSON对象通过[base64编码]生成一个字符串，该字符串即为JWT的载荷。
- 签名：包含三个部分，用base64编码的header.payload，再用加密算法加密，加密时放入一个Secret（相当于密码，存储在服务端）
	- header
	- payload
	- secret

客户端收到Token后存储下来，下回向服务端发送请求时携带这个Token，服务端收到该Token后，进行验证，通过以后就会返回给客户端想要的资源。
