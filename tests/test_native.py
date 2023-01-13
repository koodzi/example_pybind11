import native_spl


def test_native_add():
    assert native_spl.add(1,3) == 4


def test_native_sub():
    assert native_spl.sub(1,3) == -2


def test_native_blah():
    assert native_spl.blah(1,3) == -2


def test_native_pet():
    assert native_spl.Pet("Pixel").getName() == "Pixel"

    p = native_spl.Pet("Pixel")
    p.age = 100
