# Review A (reconstruction fidelity): `aa_00402d50` MbcsString_AssignFromWide_DefaultCp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d50` |
| **VA** | `0x00402d50` |
| **Canonical name** | `MbcsString_AssignFromWide_DefaultCp` (structural) |
| **Ghidra name** | `FUN_00402d50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00402d50_MbcsString_AssignFromWide_DefaultCp.md` |
| **System** | string / locale / mission UI text |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Initialize a small MBCS string object from a wide source**, using the process default code-page thunk:

1. `*this = (char*)(this + 1)` → first dword points at **inline buffer at `this+4`** (SSO-style).
2. `cp = (*PTR_FUN_00af8c9c)()` — lazy-resolved locale/ACP getter (initially `FUN_00404930`, which installs Win2k+ vs legacy path into the same pointer).
3. `FUN_00403450(this, wide, cp)` — `WideCharToMultiByte` into the object (heap if converted size > `0x80`).
4. Return `this`.

```c
// int* __thiscall  (ret 4)  — returns this
int * __thiscall FUN_00402d50(int *this, LPCWSTR wide)
{
  *this = (int)(this + 1);                 // data ptr → inline +4
  UINT cp = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00403450(this, wide, cp);            // thiscall string obj
  return this;
}
```

**Call-site pattern (MissionDef / journal):** get BSTR/text → `FUN_00402d50(wide)` → consume `*returned` as `char*` → later free heap buffer if `ptr != inline`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00402d50_*`, `reconstructed-exact/FUN_00402d50.cpp` |
| Named alias | `Named_CalleeOf_Client_UpdateMissionJournal_00402d50.cpp` |
| Function record | `functions/aa_00402d50_FUN_00402d50.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00402d50` (2026-07-29) |
| Bytes | `read_memory` 96 B — `lea eax,[esi+4]; mov [esi],eax`; call `[00af8c9c]`; `call FUN_00403450`; `ret 4` |
| IAT slot | `PTR_FUN_00af8c9c` → initially `0x00404930` (self-patching getter) |
| Callee | `FUN_00403450` — WideCharToMultiByte; heap if size > 0x80 |
| Callers | `Client_UpdateMissionJournal`, MissionDef text tags via EnsureXml, many UI string sites (`get_xrefs_to` ≥40) |
| Downstream | MissionDef_SetOwnedString_* duals take the resulting MBCS |

**Not performed:** full CString layout map, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall; stack wide arg; ret 4 | **Confirmed** | bytes |
| `*this = this+4` inline buffer bind | **Confirmed** | `lea eax,[esi+4]; mov [esi],eax` |
| Default CP via `PTR_FUN_00af8c9c` | **Confirmed** | |
| Convert via `FUN_00403450` | **Confirmed** | |
| Returns this | **Confirmed** | `mov eax,esi` |
| Object is MBCS owned-string (SSO ≤0x80 path in callee) | **High** | callee size check |
| Exact product type name (CStringA vs custom) | **Open** | layout family clear |
| Does **not** free previous `*this` | **High** | no free in body — init/assign-into-fresh-stack-obj pattern |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Bind inline ptr | Yes |
| Call CP getter | Yes |
| FUN_00403450(this, wide, cp) | Yes (thiscall this=ESI) |
| return this | Yes |

### Recovered CF

```c
MbcsString* MbcsString_AssignFromWide_DefaultCp(MbcsString* self, const wchar_t* wide) {
  self->pData = self->inlineBuf; // +4
  UINT cp = DefaultCodePageThunk();
  MbcsString_ConvertFromWide(self, wide, cp); // FUN_00403450
  return self;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `Client_UpdateMissionJournal` `0x008ae130` | NPC/header wide→MBCS |
| Caller | `MissionDef_EnsureXmlLoaded` text tags | Title/Description/… path |
| Callee | `*PTR_FUN_00af8c9c` / `FUN_00404930` | resolve/get default CP |
| Callee | `FUN_00403450` | WideCharToMultiByte into object |

---

## 6. Gaps / open

1. Dual `FUN_00403450` / full SSO field map (`+0`, `+4`, capacity).
2. Product class name.
3. Whether any call site reuses a live heap object without free (UB if so).
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — convert/init CF Confirmed; type English Open.
