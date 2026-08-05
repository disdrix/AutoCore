# Review B: `aa_00610bc0` Deliver requirement ctor (adversarial)

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00610bc0` |
| **Address** | `0x00610bc0` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_ctor` |
| **Method** | asm / `read_memory` first; decompile only as cross-check |

## Live image (authoritative)

`read_memory` `0x00610bc0` length 80:

```text
8B 44 24 04       mov eax, [esp+4]      ; owner / mission param
56                push esi
50                push eax
8B F1             mov esi, ecx          ; this
E8 D3 71 02 00    call 0x00637da0       ; base CVOGObjectiveRequirement_ctor-ish
B0 01             mov al, 1
83 C9 FF          or  ecx, 0xFFFFFFFF
88 46 20          mov [esi+0x20], al    ; GiveItemAtStart = 1
88 46 21          mov [esi+0x21], al    ; TakeItemAtEnd = 1
88 46 22          mov [esi+0x22], al    ; NPCTargetCompletes = 1
88 46 23          mov [esi+0x23], al    ; require-count = 1  ← SEAL default
C7 06 24 0F 9E 00 mov dword [esi], 0x009E0F24  ; Deliver vtable
C7 46 0C 03 00 00 00  mov dword [esi+0x0C], 3  ; type = 3  ← SEAL
89 4E 10          mov [esi+0x10], ecx   ; CBIDItem = -1
C7 46 14 00 00 00 00  mov dword [esi+0x14], 0  ; NumToDeliver = 0
89 4E 18          mov [esi+0x18], ecx   ; TargetNPCCBID = -1
89 4E 1C          mov [esi+0x1C], ecx   ; ContinentID = -1
8B C6             mov eax, esi
5E                pop esi
C2 04 00          ret 4
CC…               int3 pad
```

Call target check: `E8` at `0x00610bc9` → rel `0x000271d3` → `0x00637da0` ✓.

## Challenge matrix

| # | Challenge | Disposition | Conf |
|---|-----------|-------------|------|
| 1 | Decompiler `param_1 + 8` is offset **+0x20**, not **+0x8** | **Confirmed.** `undefined4*` scaling; asm has four stores at `+0x20..+0x23` only. | **High** |
| 2 | Type might be Collect (2) mislabeled | **Rejected.** Immediate dword **3**; Collect ctor writes **2** + different vtable. | **High** |
| 3 | Type 3 might be “UseObject” elsewhere | **Rejected for this class.** RTTI Deliver + XML `type="deliver"` + sibling Deliver methods on same vtable. Other systems’ “type 3” are different enums. | **High** |
| 4 | `+0x23` default not really 1 (decomp artifact) | **Rejected.** Explicit `mov al,1; mov [esi+23h],al`. | **High** |
| 5 | `+0x23` meaning unknown / not sealable from ctor alone | **Partial.** Default **1** sealed here. Polarity sealed by consumers (`==0` qty bypass in CargoReady / OnInventoryEvent). Ctor does not encode English name. | Default **High**; name **Probable** |
| 6 | Vtable pointer wrong endian | **Rejected.** LE `24 0f 9e 00` = `0x009e0f24`; xrefs DATA from this site only for store. | **High** |
| 7 | Base leaves Deliver vtable | **Rejected.** Base sets `009e3bac`; this body overwrites after flag defaults. | **High** |
| 8 | ABI might be cdecl / more args | **Rejected.** `RET 4` + one stack dword after thiscall ECX. | **High** |
| 9 | Factory might never call this | **Rejected.** `get_xrefs_to` → `FUN_00547050` @ `0x00547385` UNCONDITIONAL_CALL. | **High** |

## Dual A agreement

| Fact | A | B | Joint |
|------|---|---|-------|
| type `+0x0c = 3` | High | High | **Sealed High** |
| `+0x23` default **1** | High | High | **Sealed High** |
| vtable `009e0f24` | High | High | **Sealed High** |
| RTTI / class Deliver | High | High | **Sealed High** |
| `+0x20..+0x22` default 1 | High | High | **Sealed High** |
| CBID/NPC/continent −1; Num 0 | High | High | **Sealed High** |
| PDB method symbol | open | open | open (plate `_ctor`) |

## Gaps B still owns as open

- Full factory type-string → ctor table inside `FUN_00547050` (decomp heavily broken)
- Whether any other ctor also writes type **3** (no evidence; not searched exhaustively this pass)
- Runtime construction of live mission objects

## Verdict

**accept-with-gaps.** Asm seals **type=3** and **`+0x23=1`** without relying on decompiler pointer arithmetic. Dual A agrees. No invent of original method symbol beyond RTTI class + plate `_ctor`.
