# Review B (skeptical / adversarial): `aa_0096a630` AssKey_FormatAssIdLogString_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096a630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-B) |
| **Counterpart** | `reviews/A_aa_0096a630_AssKey_FormatAssIdLogString_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + call-site context only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **loads / preloads** assets | **Falsified** — only sprintf + string copy; no I/O |
| 2 | Owned solely by gfxBody / one parent | **Falsified** — **39** xrefs across AssPreloader, gfx, media |
| 3 | Returns `this` / key in EAX | **Falsified** — ESI overwritten with stack out; `MOV EAX,ESI` = **out** |
| 4 | cdecl / no stack cleanup | **Falsified** — **`RET 4`** seals one stack formal |
| 5 | Format is free-form / different string | **Falsified** — literal `"assId: [%s]"` @ `0x00aa1c18` |
| 6 | Null name crashes sprintf | **Falsified** — null → empty string via `PTR_DAT_00afa2bc` |
| 7 | Product key class name proven | **Open residual** — only `*key` as `char*` sealed; class English **Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Log-formatter role (not loader) | **High** | Wrong system placement |
| thiscall + RET 4 + out return | **High** | ABI mismatch / stack corruption |
| Format string identity | **High** | Wrong log parse / diagnostics |
| Null → empty | **High** | Crash vs empty id display |
| Key product type English | Medium | Naming only; layout first-dword sealed |
| All 39 callers share key layout | Medium | Rare exotic key would misread |

---

## 3. Cross-check against raw + bytes

```
SEH setup; sub esp, 0x124
tmp = basic_string()
name = *ecx_key
if name == 0: name = [0x00afa2bc]   // → ""
sprintf(buf260, "assId: [%s]", name)
tmp = buf
out = tmp (copy-ctor)
~tmp
restore SEH; add esp, 0x130; ret 4
eax = out
```

Bytes: `MOV ESI,ECX`; IAT calls for string ops + sprintf; epilogue `C2 04 00`.

Do **not**:
- Treat as preload worker / asset resolver
- Merge with tree iterator `00457cc0` (unrelated co-partition)
- Invent a single owning class from one scaffold alias

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — shared diagnostic helper
string FormatAssIdLogString(AssKeyView key)
{
    var name = key.Name ?? "";
    return string.Format("assId: [{0}]", name);
}
// Retail: thiscall ECX=key*, out basic_string* on stack, RET 4, returns out*
// Key: first field char* (AssPreloader node+0xC common pattern)
```

Server AutoCore may not need this client log helper unless matching client diagnostics.

---

## 5. Open questions

1. PDB/RTTI name of key type.
2. Exhaustive key-layout audit across all 39 xrefs.
3. Whether any caller expects SSO buffer address stability beyond `c_str` use.

**Verdict:** **accept-with-gaps**
