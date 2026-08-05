# Review A (reconstruction fidelity): `aa_007182e0` `_com_error::~_com_error`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007182e0` |
| **VA** | `0x007182e0` |
| **Canonical name** | `_com_error::~_com_error` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007182e0__com_error_dtor.md` |
| **System** | `crt-com` / MSVC COM support (`comdef` / `_com_error`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` + `get_function_by_address` + xrefs |
| **Verdict** | **accept** (library dtor sealed; not game logic) |

---

## 1. Purpose

MSVC `_com_error` **virtual destructor** body:

1. Re-install vftable `PTR_FUN_00a14034` at `this+0` (standard MSVC dtor prolog)
2. If `IErrorInfo*` @ `this+8` ≠ null → `Release` via COM `vtbl+8`
3. If description buffer @ `this+0xC` ≠ null → `LocalFree` that `HLOCAL`
4. Return (no operator delete here — scalar/vector deleting dtors are separate)

Ghidra library match: **Visual Studio 2003 Debug**  
`public: virtual __thiscall _com_error::~_com_error(void)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007182e0_FUN_007182e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007182e0_FUN_007182e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007182e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007182e0_FUN_007182e0.md` |
| Live decompile | Ghidra name `~_com_error` |
| IAT | `LocalFree` via `[0x009c6180]` (`FF 15 80 61 9C 00`) |

---

## 3. Seal: body bytes + CF (High)

Body range: **`007182e0`–`00718324`**.

`read_memory` @ `0x007182e0`:

```
55 8B EC 51 89 4D FC             ; prologue; this → [ebp-4]
8B 45 FC C7 00 34 40 A1 00       ; *this = &PTR_FUN_00a14034
8B 4D FC 83 79 08 00 74 12       ; if (this+8 == 0) skip Release
… 52 FF 50 08                    ; push errinfo; call [vtbl+8] = Release
8B 4D FC 83 79 0C 00 74 0D       ; if (this+0xC == 0) skip free
8B 55 FC 8B 42 0C 50             ; push *(this+0xC)
FF 15 80 61 9C 00                ; call dword ptr [LocalFree IAT @ 009c6180]
8B E5 5D C3                      ; leave; ret  (no stack args)
; CC … then unrelated jmp/import stubs
```

Hex (body through `ret`):

```
558bec51894dfc8b45fcc7003440a1008b4dfc8379080074128b55fc8b42088b4dfc8b51088b0052ff5008
8b4dfc83790c00740d8b55fc8b420c50ff1580619c008be55dc3
```

| Claim | Evidence | Conf |
|---|---|---|
| Library single-match virtual dtor | Ghidra plate | **Confirmed** |
| Release = COM `vtbl+8` | `FF 50 08` | **High** |
| Description freed with `LocalFree` only if non-null | branch + IAT call | **High** |
| Does **not** free `this` itself | no `operator delete` in body | **High** |
| Same vftable imm as ctors | `00a14034` | **High** |
| `__thiscall`; plain `ret` (`C3`) | epilogue | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |
| Not game domain | CRT COM | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name / signature | **Confirmed** | library + bytes |
| Resource pairing with ctors | **High** | AddRef@ctor ↔ Release@dtor; LocalFree for lazy msg |
| Deleting-dtor wrapper identity (`0x00718250`) | **Probable** | vftable slot0 points there; not dualed in this OWN unit |
| Port for server | **N/A** | client COM |

---

## 5. Callers (sample)

`get_bulk_xrefs` → call from **`0x0071825a`** (inside `0x00718250` cluster — typical scalar deleting destructor that invokes `~_com_error` then `operator delete`). Matches MSVC virtual-dtor shape.

---

## 6. Gaps

1. Full dual of scalar deleting dtor `0x00718250` (adjacent; out of this OWN list).
2. Runtime / bit-exact deferred.
3. Exact `ErrorMessage` allocator that pairs with `LocalFree` (not this VA).

**Verdict:** **accept** — sealed MSVC `_com_error::~_com_error`; dual complete for OWN unit.
