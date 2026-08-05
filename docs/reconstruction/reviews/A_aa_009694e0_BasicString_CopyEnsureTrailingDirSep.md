# Review A (reconstruction fidelity): `aa_009694e0` BasicString_CopyEnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009694e0` |
| **VA** | `0x009694e0`–`0x009695b1` exclusive (**209 B**) |
| **Canonical name** | `BasicString_CopyEnsureTrailingDirSep` |
| **Ghidra name** | `FUN_009694e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-A) |
| **Counterpart** | `reviews/B_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` |
| **System** | assManager / path-string normalize helper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 209 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Copy a path `basic_string` into an out-parameter, ensuring a trailing directory separator `/` when the source is non-empty and does not already end with `:`, `/`, or `\`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-A append) | `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicString_CopyEnsureTrailingDirSep.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_009694e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` |
| Parent dual | `aa_00969830` StringVec_PushFront_EnsureTrailingDirSep (W31-E) |
| Nested helper decompile | `FUN_00416510` (copy + `operator+=`) |
| Live | decompile + 209 B hex |

---

## 3. Signature (sealed)

```c
// cdecl; returns out*
MsvcBasicString* BasicString_CopyEnsureTrailingDirSep(
    MsvcBasicString* out,
    const MsvcBasicString* src);
```

| Formal | Source | Conf |
|---|---|---|
| out | stack arg1; held in ESI; returned EAX | **High** |
| src | stack arg2 | **High** |
| convention | cdecl (`C3`, frame `add esp,0x28`) | **High** |
| SEH | `LAB_009ab825` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009ab825; sub esp,0x1c
if (src->_Mysize == 0) → copy_ctor(out,src); return out
data = SSO? src+4 : *(char**)(src+4)
last = data[size-1]
if last ∉ {':','/','\\'}:
  FUN_00416510(&tmp, src, '/')   // append path
  copy_ctor(out, &tmp); dtor(tmp); return out
else:
  copy_ctor(out, src); return out
```

| Stage | Match | Conf |
|---|---|---|
| Empty early-out | `8B 48 14 85 C9 75 1B` | **High** |
| SSO vs heap | `83 78 18 10` | **High** |
| Charset tests | `80 F9 3A/2F/5C` | **High** |
| Append `/` | `6A 2F` + `FUN_00416510` | **High** |
| IAT copy/dtor | `[0x009c62ec]` / `[0x009c62f4]` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (209 B) — see raw W32-A append.

Entry: `6A FF 68 25 B8 9A 00` (SEH).  
Epilogues: `83 C4 28 C3` (three return sites).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_009696c0`, `FUN_009697a0`, `FUN_00969830` |
| Callees | IAT copy-ctor, IAT dtor, `FUN_00416510` |

---

## 7. Gaps

1. Product English for path-list / search-root role.  
2. Nested `FUN_00416510` not dual-owned here.  
3. IAT slot demangle beyond use-site role.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Trailing-sep rules, SSO layout offsets, cdecl out-string ABI, and caller binding to AssManager path helpers are sealed. Residual product English + nested helper plate → **accept-with-gaps**.
