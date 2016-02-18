var proxy = new Proxy({}, {
	setPrototypeOf(target, value) {
		print("`setPrototypeOf` invoked");
		return false;
	}
});
try {
	Object.setPrototypeOf(proxy, {});
} catch (e) {
	print(String(e));
}

try {
	proxy.__proto__ = {};
} catch (e) {
	print(String(e));
}
