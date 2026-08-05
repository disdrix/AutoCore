# Review B (skeptical / adversarial): `aa_004c3ac0` CVOGObject_GetActivePositionPtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-O) |
| **Counterpart** | `reviews/A_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **writes** position / is the gated setter | **Falsified** — pure load+select; three `ret` paths; no stores; writer is sibling `004c3a40` |
| 2 | Read gate uses mask **`0xC7`** like the setter | **Falsified** — imm is **`7`** only (`test …,07`) |
| 3 | Phys return is `phys + 0x3c + 0xb0` (struct field) | **Falsified for literal bytes** — `mov eax,[phys+0x3c]; add eax,0xb0` = **`*(phys+0x3c)+0xb0`** |
| 4 | Returns a float value / copies vec | **Falsified** — returns **pointer** in EAX; no FPU |
| 5 | Has stack args / `ret 4` | **Falsified** — bare `C3`; ECX only |
| 6 | Non-leaf (calls helper) | **Falsified** — 48-byte leaf |
| 7 | Name is PDB-proven | **Unproven** — role **Inferred** from offsets + sibling writer dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Three-way CF + offsets | **High** | Wrong pose source in motion port |
| Mask imm `7` vs writer `0xC7` | **High** | Gate mismatch bugs |
| Phys pointer arithmetic form | **High** | AV if treated as `phys+0xec` |
| Product English name | **Low / open** | Docs only |
| Phys object product type | **Inferred** | Wrong wrapper if named as Havok without seal |

---

## 3. Cross-check against raw + bytes

```
typeOff = *(*(self+4)+4)
if ((*(u8*)(self+typeOff+0xb8) & 7) == 0) return self+0x240
if (*(self+8) != 0) return *( *(self+8)+0x3c ) + 0xb0
return self+typeOff+0x84
```

Clean must **not** invent stores, NaN traps, or mask `0xC7`.

---

## 4. Surviving contract for AutoCore

```c
// Port of CVOGObject_GetActivePositionPtr_Inferred
// Returns pointer to active position block (not a copy).
float* GetActivePositionPtr(Object* self) {
  int typeOff = TypeOffset(self); // *(*(self+4)+4)
  if ((ComponentFlags(self, typeOff) & 7) == 0)
    return (float*)((char*)self + 0x240);
  void* phys = *(void**)((char*)self + 8);
  if (phys)
    return (float*)(*(char**)((char*)phys + 0x3c) + 0xb0);
  return (float*)((char*)self + typeOff + 0x84);
}
// Pair with SetLocalPosition4_Gated (mask 0xC7) for write path.
// Do not collapse phys form to phys+0xEC.
```

---

## 5. Open questions

1. Product method name.
2. Identity of phys link / base at `+0x3c`.
3. Whether all consumers treat return as vec3 or vec4.
4. Runtime golden vs client — open.

**Verdict:** **accept**
