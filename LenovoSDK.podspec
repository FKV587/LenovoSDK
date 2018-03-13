Pod::Spec.new do |s|

  s.name                = "LenovoSDK"
  s.version             = "0.0.2"
  s.summary             = "LenovoSDK"
  s.homepage            = "https://github.com/FKV587/LenovoSDK"
  s.license             = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "FK" => "263699451@qq.com" }
  s.platform            = :ios, "8.0"
  s.source              = { :git => "https://github.com/FKV587/LenovoSDK.git", :tag => s.version }
  s.source_files        = "Classes/**/*"
  s.dependency          "AFNetwork"
  s.requires_arc        = true

end
