#
#  Be sure to run `pod spec lint LenovoSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "LenovoSDK"
  s.version      = "0.0.1"
  s.summary      = "LenovoSDK"
  s.description  = <<-DESC
A short description of LenovoSDK
                   DESC

  s.homepage     = "http://github.com/FKV587/LenovoSDK"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = = { "FK" => "263699451@qq.com" }

  s.platform     = :ios, "8.0"

  s.source       = { :git => "http://github.com/FKV587/LenovoSDK.git", :tag => "#{s.version}" }

  s.source_files  = "Classes", "Classes/**/*"
  s.exclude_files = "Classes/Exclude"

 s.requires_arc = true


end
