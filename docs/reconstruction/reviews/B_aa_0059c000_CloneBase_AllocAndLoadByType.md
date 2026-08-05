# Review B (skeptical / adversarial): `aa_0059c000` CloneBase_AllocAndLoadByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059c000` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-F) |
| **Counterpart** | `reviews/A_aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims). No `disassemble_bytes`. Own VA only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is “the VOG_DEBUG_STOP function” (parent-seed) | **Falsified** — parent logs that string on **non-zero return** of this unit; body has no debug string |
| 2 | thiscall ECX = record | **Falsified** — stack arg + bare `ret` |
| 3 | Always allocates (no cache skip) | **Falsified** — `DAT_00b04694` path can skip switch |
| 4 | Unknown type returns 0 | **Falsified** — returns `0x80004005` |
| 5 | Type 0xe is generic loader | **Falsified** — `VehicleDb_LoadCloneBase`, size `0x744` |
| 6 | Clean may invent product type names for every case | **Reject invention** — only seal structural sizes + named loaders present in decompile |
| 7 | Function is inventory equip logic | **Falsified** — gamedata materialize; equip uses other VAs |
| 8 | Body ends before switch tables | **Falsified** — Ghidra body through `0059c443`; tables immediately follow |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type→size→loader map | **High** | wrong clonebase layouts / vehicle mass path |
| cdecl + E_FAIL default | **High** | wrong port ABI / error handling |
| Record offsets | **High** | corrupt catalog materialize |
| Structural name | **High** as structural | over-claiming PDB English |
| Cache path full semantics | **Medium** | `FUN_00540850` not owned |
| Double name convert on success | **Medium** | decompiler may double-print; verify before optimizing away |

---

## 3. Cross-check against raw + bytes

```
// default exit (tail region):
mov eax, 0x80004005
pop esi
mov fs:[0], ecx
add esp, 0x118
ret
```

Any clean plate that returns 0 on unknown type, uses thiscall, or implements only vehicle arm is **wrong** for this VA.

Parent-seed alias is **auto-rename debt** — keep as alias only.

---

## 4. Surviving contract for AutoCore

```c
// Port: type-dispatch clonebase materialize (not equip, not VOG_DEBUG_STOP)
int32_t CloneBase_AllocAndLoadByType(CloneBaseRecord* rec); // cdecl

// record+0x38 type → alloc size + loader; store at +0x3c
// unknown type → E_FAIL (0x80004005)
// success → 0 after name fill
// type 0xe → VehicleDb_LoadCloneBase path (size 0x744)
```

Do **not** invent full product enum names without string/PDB evidence. Keep FUN_* loaders until dual-owned.

---

## 5. Open questions

1. PDB / product symbol.
2. Full type catalog English.
3. Cache enable flag + `FUN_00540850` dual.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
