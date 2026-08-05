# Review A (reconstruction fidelity): `aa_007b6420` Path_GetFileName

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6420` |
| **VA** | `0x007b6420`–`0x007b644f` |
| **Canonical name** | `Path_GetFileName` (Ghidra `FUN_007b6420`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A, W17-L) |
| **Counterpart** | `reviews/B_aa_007b6420_Path_GetFileName.md` |
| **System** | path utilities / ND resource load |
| **Verdict** | **accept** — basename helper sealed |

---

## 1. Purpose

Return a pointer to the **filename component** of a path: one past the last `'\\'` or `'/'`. If neither separator appears, return the original path pointer. Pure string utility used heavily by ND UI / XML path loaders and path-exists search (`FUN_007b6450`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007b6420_FUN_007b6420.md` |
| Annotated | `docs/reconstruction/raw/aa_007b6420_FUN_007b6420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b6420.cpp` / `Path_GetFileName.cpp` |
| Function record | `docs/reconstruction/functions/aa_007b6420_FUN_007b6420.md` |
| Live Ghidra | `decompile_function` + `force_decompile` (**identical**) |
| | `read_memory` 80 B @ `0x007b6420` |
| | `get_function_pcode` basic |
| | `analyze_function_complete` (22 xrefs; callee `strrchr`) |
| | `get_assembly_context` sample sites (`LEA EDI` / `MOV EDI`) |
| Tools avoided | `disassemble_bytes` |

**Dual decompile:**

```
char *FUN_007b6420(void) {
  char *bs = strrchr(unaff_EDI, 0x5c);
  char *sl = strrchr(unaff_EDI, 0x2f);
  if (bs == NULL) {
    if (sl == NULL) return unaff_EDI;
  } else if (sl < bs) {
    sl = bs;
  }
  return sl + 1;
}
```

---

## 3. Signature

```c
// Retail ABI: path in EDI; return char* in EAX; plain RET
// Port: char *Path_GetFileName(char *path);
```

| Item | Evidence |
|---|---|
| Path register | `PUSH EDI` into both `strrchr`; call sites `LEA/MOV EDI, path` |
| Separators | imm `0x5C` (`\\`), `0x2F` (`/`) |
| Callee | IAT `[0x009c662c]` → `strrchr` |
| Stack clean | `ADD ESP,0x10` after two cdecl calls |
| Body end | second `RET` @ `0x007b644f`; next fn `FUN_007b6450` @ `0x007b6450` |

---

## 4. Control flow (sealed)

```
bs = strrchr(path, '\\')
sl = strrchr(path, '/')
if (bs == NULL) {
  if (sl == NULL) return path
  return sl + 1
}
// bs non-null:
if (sl < bs) sl = bs   // also true when sl == NULL (null < ptr)
return sl + 1
```

Equivalent: `return path_past_max(last_bs, last_sl)` or `path`.

---

## 5. Machine bytes (`read_memory` @ `0x007b6420`, 48 B)

```
53 8B 1D 2C 66 9C 00 56 6A 5C 57 FF D3
6A 2F 57 8B F0 FF D3 83 C4 10
85 F6 75 09 85 C0 75 0B 5E 8B C7 5B C3
3B F0 76 02 8B C6 5E 83 C0 01 5B C3
```

---

## 6. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| CF / both separators | **High** | bytes + dual decompile |
| EDI ABI | **High** | call sites + pushes |
| Basename semantics | **High** | FUN_007b6450 concatenates onto roots |
| Studio name | **Tentative** | inferred `Path_GetFileName` |
| Does not strip extension | **High** | no further processing |

---

## 7. Gaps

1. Original symbol (may match internal ND path helper, not Win32 export name).
2. Exhaustive caller catalog (22 xrefs — not all owned).

---

## 8. AutoCore impact

- Use `Path.GetFileName` / last-separator logic when matching client path resolution.
- Preserve dual-separator support (`\` and `/`).
- Result aliases into the source string — lifetime tied to path buffer.
