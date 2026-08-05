# Review B (skeptical / adversarial): `aa_00996d70` ResourceCache_Subobj14_Configure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-V) |
| **Counterpart** | `reviews/A_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN_00996d70(undefined1)` is full ABI | **Falsified** — EAX subobj + EBX size + stack flag + `RET 4` |
| 2 | `in_EAX` is accidental / phantom only | **Falsified** — `MOV EDI,EAX` first real work; callers LEA/MOV EAX to host+0x14 |
| 3 | Size comes from stack or this+field inside unit | **Falsified** — unit never loads size; `00989b00` uses EBX; callers set EBX from host+0x10 |
| 4 | `FUN_00989b00(1)` uses stack flag | **Partial falsify** — push is constant **1** (`ESI=1`); stack flag only written to `+0x50` |
| 5 | ECX-thiscall on whole ResourceCache | **Falsified** — configure is subobject; parent is EDI host |
| 6 | Scaffold `Named_CalleeOf_*assManager*` plate | **Reject** — ResourceCache family from W31-F parent dual |
| 7 | Product name Confirmed | **Open** — keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX subobj + stack flag + RET 4 | **High** | Wrong ABI |
| EBX size into realloc | **High** | Wrong buffer size |
| Offsets 0x2C/0x38/0x48/0x4C/0x50 | **High** | Wrong layout |
| ResourceCache+0x14 embedding | **High** | Wrong parent map |
| `00989b00(1)` vs flag coupling | **High** | Wrong flag path into buffer helper |
| Product English | **Low** | Naming |
| Unowned callee full contracts | **Medium** | Nested residual |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 76 B hex ends `5F 5E 59 C2 04 00`.
- Body range Ghidra `00996d70–00996dbb` = 0x4C.
- Caller `00989ef0`: `LEA EAX,[EDI+0x14]` then call (W31-F sealed).
- Caller `00989d50`: `LEA EDI,[EBX+0x14]`; later `MOV EBX,[EBX+0x10]; PUSH 0; MOV EAX,EDI; call`.
- Callee `00989b00`: `MOV ESI,EAX` (align); `TEST EBX`; `MOV [EDI+0x14],EBX` (size); `_aligned_malloc`.
- Only 2 xrefs — both ResourceCache-family.

---

## 4. Surviving contract for AutoCore

```
// Port as subobject configure (not whole-cache thiscall):
void ConfigureSubobj14(void *subobj /*EAX*/, uint32_t size /*EBX*/, uint8_t flag) {
  ClearList(subobj + 0x2C);
  ResetVec(subobj + 0x38, /*arg*/ 9);
  *(u32*)(subobj + 0x48) = 1;
  *(u32*)(subobj + 0x4C) = 1;
  FreeAlignedState(subobj);           // FUN_009899a0
  *(u8*)(subobj + 0x50) = flag;
  ReallocAligned(subobj, /*align*/ 4, size, /*helper_flag*/ 1); // FUN_00989b00
}
// Parent SetField10AndConfigure: host+0x10 = size; then this(host+0x14, size, flag).
// Do not invent product field names without strings/RTTI.
```

---

## 5. Verdict

Adversarial pass confirms A on register formals (EAX/EBX), offsets, RET 4, and ResourceCache+0x14 family. Gaps: product English, full unowned callee duals, runtime. **accept-with-gaps**.
