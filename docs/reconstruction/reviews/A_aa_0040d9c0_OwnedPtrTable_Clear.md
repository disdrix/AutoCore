# Review A (reconstruction fidelity): `aa_0040d9c0` OwnedPtrTable_Clear

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d9c0` |
| **VA** | `0x0040d9c0`–`0x0040da23` |
| **Canonical name** | `OwnedPtrTable_Clear` (Ghidra `FUN_0040d9c0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A, W18-M) |
| **Counterpart** | `reviews/B_aa_0040d9c0_OwnedPtrTable_Clear.md` |
| **System** | container / resource cleanup |
| **Verdict** | **accept-with-gaps** — CF + ESI ABI sealed; product type English open |

---

## 1. Purpose

Clear an **owned pointer table** (this in **ESI**):

1. Spin `liveCount` (`+0x10`) to zero; when it hits 0, null `cached` (`+0x0C`).
2. For each element in reverse, `operator_delete` if non-null.
3. `operator_delete` the array buffer; zero `count` (`+0x08`) and `data` (`+0x04`).

Appears on resource-cache / preloader teardown paths (e.g. `NDResourceCache_LookupOrCreate`, `Named_assPreloader` callee chain).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d9c0_FUN_0040d9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d9c0_FUN_0040d9c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040d9c0.cpp` / `OwnedPtrTable_Clear.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d9c0_FUN_0040d9c0.md` |
| Live Ghidra | `decompile_function` + `force_decompile` `0x0040d9c0` (**identical**) |
| | `read_memory` 128 B @ `0x0040d9c0` |
| | `analyze_function_complete` (19 xrefs; callee `operator_delete`) |
| | `get_assembly_context` on call sites (ESI setup) |
| | wrappers: `FUN_0040d910` (SEH), thunk `0x0040fd50` |
| Tools avoided | `disassemble_bytes` (policy) |

**Dual A/B decompile agreement:** identical.

---

## 3. Signature

```c
// this in ESI; plain RET; no stack args cleaned by callee
void OwnedPtrTable_Clear(OwnedPtrTable *self /* ESI */);
```

| Item | Evidence |
|---|---|
| ESI = this | `MOV ESI,ECX` @ `0x00456b91`; `LEA ESI,[EDI+0x52c]` @ `0x0090c52c`; `LEA ESI,[ESP+…]` stack temps |
| Return | plain `RET`; void |
| Body range | `0x0040d9c0`–`0x0040da23` (~100 B) |
| Callees | `operator_delete` (cdecl; returns) |

---

## 4. Control flow (sealed)

```
while (this[+0x10] != 0) {
  this[+0x10]--;
  if (this[+0x10] == 0) this[+0x0C] = 0;
}
i = this[+0x08]
while (i > 0) {
  p = this[+0x04][i-1]
  i--
  if (p) operator_delete(p)
}
if (this[+0x04]) operator_delete(this[+0x04])
this[+0x08] = 0
this[+0x04] = 0
```

---

## 5. Machine bytes (`read_memory` @ `0x0040d9c0`)

```
53 33 DB 39 5E 10 74 19 8B 46 10 3B C3 74 0D 83 C0 FF
3B C3 89 46 10 75 03 89 5E 0C 39 5E 10 75 E7 57 8B 7E 08
3B FB 76 22 8D A4 24 00 00 00 00 8B 46 04 8B 44 B8 FC
83 EF 01 3B C3 74 09 50 E8 .. .. .. .. 83 C4 04 3B FB 77 E5
8B 46 04 3B C3 5F 74 09 50 E8 .. .. .. .. 83 C4 04
89 5E 08 89 5E 04 5B C3
```

`ADD ESP,4` after each delete confirms **not** noreturn.

---

## 6. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ESI this + free CF | **High** | bytes + call sites |
| Offsets +4/+8/+0C/+10 | **High** | |
| operator_delete returns | **High** | |
| Element typed dtor | **Open** | only raw delete |
| Product class name | **Tentative** | inferred `OwnedPtrTable` |
| liveCount semantics | **Tentative** | spin-down shape only |

---

## 7. Gaps (non-blocking for CF seal)

1. Studio / RTTI type name.
2. Whether elements need a virtual dtor before `operator_delete` (body does not call one).
3. Why live counter is spun rather than assigned 0 (reentrancy? codegen?).
4. Relationship of nested subobject at `+0x52c` on larger owners.

---

## 8. AutoCore impact

- Porting resource-cache teardown must free **elements then buffer**, null counts.
- Do not assume ECX thiscall without an ESI adaptor.
- Ignore Ghidra noreturn warnings on `operator_delete` here.
