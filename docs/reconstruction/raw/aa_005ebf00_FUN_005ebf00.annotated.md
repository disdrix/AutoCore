# Annotated low-level: FUN_005ebf00 / VOGPhysics_SphereQueryCollect_Dtor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005ebf00` |
| VA | `0x005ebf00`–`0x005ebf67` (104 B / `0x68`) |
| System | interaction-activation |
| Date | 2026-08-05 (R12-038 dual seal) |
| Proposed name | `VOGPhysics_SphereQueryCollect_Dtor_Inferred` |
| Ghidra name | `FUN_005ebf00` |

---

## Machine-level notes

- Source: raw capture + live re-verify (decompile ≡ original raw CF; assembly seals thiscall + tail JMP).
- **ABI sealed:** thiscall ECX=self; no stack args; ends in **JMP** `FUN_006343d0` (not RET).
- Prefer assembly where decompiler labels `__fastcall` / omits this on callees / shows free size as raw capacity without `AND 0x7fffffff`.
- Destroys **derived** collect triad at **+0xC0** then chains to base dtor for **0xC0** core.

---

## Pseudocode (annotated)

```c
// thiscall: ECX = self (0xD0 sphere-query collect object*)
// no stack args; tail-jumps to base dtor
void __thiscall FUN_005ebf00(uint32_t *self /* ECX */)
{
  int i;

  i = (int)self[0x31];             // +0xC4 count
  *self = (uint32_t)&PTR_FUN_009dce90;  // reinstall derived vtbl (MSVC dtor pattern)

  // Walk collect buffer reverse: elements are 8-byte slots, first dword = object*
  for (i = i - 1; i >= 0; i = i - 1) {
    uint32_t *entry_obj = *(uint32_t **)(self[0x30] + i * 8);  // +0xC0 begin
    // thiscall release: ECX = entry_obj; CALL [vtbl+0x14]
    (**(code **)(*entry_obj + 0x14))(/*this=entry_obj*/);
  }
  self[0x31] = 0;                  // count = 0

  // Free backing store if capacity is non-negative (empty sentinel is 0x80000000)
  if ((int)self[0x32] >= 0) {      // +0xC8 capacity
    int cap = (int)(self[0x32] & 0x7fffffffu);
    // allocator free: (*DAT_00b05060)->vtbl[+0x14](begin, cap*8, tag 0x12)
    (**(code **)(*DAT_00b05060 + 0x14))(
        (void *)self[0x30],
        cap * 8,
        0x12);
  }

  // Tail: MOV ECX,self; JMP FUN_006343d0  — base query-object dtor
  FUN_006343d0(/*this=self*/);
}
```

---

## Layout (derived collect + base)

| Off | Role in this dtor |
|----:|-------------------|
| `+0x00` | reinstall vtbl `009dce90` |
| `+0xC0` | collect buffer begin (free + walk) |
| `+0xC4` | collect count (walk then zero) |
| `+0xC8` | collect capacity (`>=0` → free; `0x80000000` empty sentinel skips free) |
| `+0x00..+0xBF` | base core destroyed by tail `FUN_006343d0` |

Object size (from ctor/factory peers): **0xD0**; pool tag on whole free (scalar dtor): **0x2C**.

---

## Call graph (OWN = this VA only)

```text
FUN_005ebf00  VOGPhysics_SphereQueryCollect_Dtor_Inferred  [OWN R12-038]
  ├─ vcall [*(entry_obj)].vtbl[+0x14]   per-element release   [dynamic]
  ├─ (*DAT_00b05060)->vtbl[+0x14]       buffer free tag 0x12  [allocator]
  └─ JMP FUN_006343d0                   base query dtor       [residual]

FUN_005ebf70  scalar-deleting dtor                            [residual]
  ├─ CALL FUN_005ebf00                                        [OWN]
  └─ if (flags&1) free(self, size@+4, tag 0x2C)
```

---

## Decompiler vs assembly corrections

| Decompiler display | Assembly truth |
|---|---|
| `void __fastcall` | **thiscall** (`MOV EDI,ECX`) |
| `FUN_006343d0()` free call | **JMP** after `MOV ECX,EDI` (thiscall tail) |
| free size `param_1[0x32]*8` | `(capacity & 0x7fffffff) * 8` (AND before ×8) |
| element vcall no this | ECX loaded from buffer entry (thiscall on element) |

---

## Open questions

1. Product/PDB class English for vtbl `009dce90` (no RTTI on DATA xrefs).
2. Exact type of 8-byte collect element (obj* + padding/tag?).
3. Semantic of vtbl slot `+0x14` release on elements.
4. Dual residual base dtor `FUN_006343d0` / scalar dtor `FUN_005ebf70`.
5. Runtime Confirmed / bit-exact / differential.
