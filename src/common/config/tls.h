#ifndef SSF_COMMON_CONFIG_TLS_H_
#define SSF_COMMON_CONFIG_TLS_H_

#include <string>

#include <boost/property_tree/ptree.hpp>

namespace ssf {
namespace config {

class TlsParam {
 public:
  enum class Type { kFile = 0, kBuffer };
  TlsParam(Type param_type, const std::string& param_value);

  void Set(Type param_type, const std::string& param_value);

  std::string ToString() const;
  bool IsBuffer() const;
  std::string value() const { return value_; }

 private:
  Type type_;
  std::string value_;
};

class Tls {
 public:
  using PTree = boost::property_tree::ptree;

 public:
  Tls();

 public:
  void Update(const PTree& pt);

  void Log() const;

  const TlsParam& ca_cert() const { return ca_cert_; }
  const TlsParam& cert() const { return cert_; }
  const TlsParam& key() const { return key_; }
  const std::string& key_password() const { return key_password_; }
  const TlsParam& dh() const { return dh_; }
  const std::string& cipher_alg() const { return cipher_alg_; }

 private:
  // CA certificate
  TlsParam ca_cert_;
  // Certificate
  TlsParam cert_;
  // Certificate key
  TlsParam key_;
  // Key password
  std::string key_password_;
  // Diffie-Hellman ephemeral parameters
  TlsParam dh_;
  // Cipher suite algorithms
  std::string cipher_alg_;
};

}  // config
}  // ssf

#endif  // SSF_COMMON_CONFIG_TLS_H_