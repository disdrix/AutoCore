# Review A (reconstruction fidelity): `aa_00403450` MbcsString_ConvertFromWide

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403450` |
| **VA** | `0x00403450` |
| **Canonical name** | `MbcsString_ConvertFromWide` (structural) |
| **Ghidra name** | `FUN_00403450` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-L) |
| **Counterpart** | `reviews/B_aa_00403450_MbcsString_ConvertFromWide.md` |
| **System** | string / locale / MBCS owned-string |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Wide → MBCS convert into a string object** under an explicit code page:

1. If `wide == NULL` → `*this = 0`; return.
2. `cch = lstrlenW(wide)`; `size = (cch+1)*2`.
3. If `size > 0x80` → `*this = malloc(size)`; OOM → `FUN_004048e0(0x8007000E)` (throw).
4. Else → write through **existing** `*this` (caller SSO: typically `*this = this+4` via `FUN_00402d50`).
5. `WideCharToMultiByte(cp, 0, wide, cch+1, (LPSTR)*this, size, NULL, NULL)`.
6. If result `== 0` → `FUN_004048c0()` (GetLastError → throw).

```c
// void __thiscall  (ret 8)
void __thiscall FUN_00403450(void **this, LPCWSTR wide, UINT cp)
{
  if (!wide) { *this = 0; return; }
  int cch = lstrlenW(wide);
  size_t size = (cch + 1) * 2;
  if ((int)size > 0x80) {
    void *p = malloc(size);
    *this = p;
    if (!p) FUN_004048e0(0x8007000E); // noreturn
  }
  if (!WideCharToMultiByte(cp, 0, wide, cch + 1, (LPSTR)*this, (int)size, 0, 0))
    FUN_004048c0(); // noreturn on fail
}
```

**Primary wrapper:** `FUN_00402d50` binds inline buffer, resolves default CP via `PTR_FUN_00af8c9c`, then calls this.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00403450_*`, `reconstructed-exact/FUN_00403450.cpp` |
| Named alias | `Named_CalleeOf_Client_OnServerConnectionTerminated_00403450.cpp` |
| Function record | `functions/aa_00403450_FUN_00403450.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00403450` (2026-07-29) |
| Bytes | `read_memory` 128 B — `mov ebx,ecx`; null → `*ebx=0; ret 8`; `cmp edi,0x80`; `push 0x8007000E`; `WideCharToMultiByte`; `ret 8` |
| Wrapper dual | `A_aa_00402d50_MbcsString_AssignFromWide_DefaultCp` (calls this) |
| Throw helpers | `FUN_004048e0` = `_CxxThrowException`; `FUN_004048c0` = GetLastError→HRESULT→throw |

**Not performed:** full product CString layout map, Launcher, runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall; stack wide+cp; **ret 8** | **Confirmed** | bytes |
| Null wide → `*this=0` | **Confirmed** | |
| Size `(len+1)*2`; heap iff `>0x80` | **Confirmed** | `cmp edi,0x80` / `jle` |
| OOM throw `0x8007000E` | **Confirmed** | |
| Convert fail → `004048c0` | **Confirmed** | |
| Does **not** free prior `*this` before large malloc | **High** | no free in body |
| ≤0x80 path needs pre-bound `*this` | **Confirmed** | no store when size≤0x80 |
| Object is MBCS owned-string family | **High** | with `00402d50` |
| Exact product type name | **Open** | structural only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null wide clear | Yes |
| lstrlenW + size | Yes |
| Heap branch >0x80 | Yes |
| WideCharToMultiByte | Yes |
| Fail / OOM throw | Yes |

### Recovered CF

```c
MbcsString_ConvertFromWide(self, wide, cp):
  if !wide: self.p = null; return
  size = (lenW(wide)+1)*2
  if size > 0x80:
    self.p = malloc(size) or throw E_OUTOFMEMORY
  // else self.p already points at inline
  if !WideCharToMultiByte(... into self.p ...): throw last-error
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00402d50` | default-CP assign/init |
| Callers | 30+ UI/mission/terrain string sites | wide→MBCS utility |
| Callee | `lstrlenW` / `malloc` / `WideCharToMultiByte` | Win32 |
| Callee | `FUN_004048e0` / `FUN_004048c0` | throw paths |

---

## 6. Gaps / open

1. Product class name (`CStringA` vs custom).
2. Full capacity / free-on-dtor map (sibling duals).
3. Runtime deferred.
4. Whether any site skips SSO bind on small strings.

**Verdict:** **accept-with-gaps** — convert CF and ABI Confirmed; product name Open.
