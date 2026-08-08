# Review B (skeptical / adversarial): `aa_006c6c50` CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-039) |
| **Counterpart** | `reviews/A_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `Named_CalleeOf_Named_VOG_DEBUG_STOP` product role | **Falsified** — `VOG_DEBUG_STOP` is parent null-world fail string inside GetObjectsInArea; this leaf is the filter gate, not debug stop |
| 2 | Skill-specific helper / status-effect path | **Falsified** — sole xref is GetObjectsInArea AABB loop; no skill strings in body |
| 3 | Returns bool in EAX as primary result | **Clarify** — result is **out-byte**; EAX holds `out*` after both paths (parent `CMP BYTE PTR [EAX],0`). Ports must use out-param, not treat EAX as 0/1 |
| 4 | `__cdecl` / `RET 0` / 2-arg only | **Falsified** — epilogue **`RET 0xC`** (3 stack dwords); ECX this |
| 5 | Full 32-bit row/bit indices (no mask) | **Falsified** — both indices **`& 0x1F`** before use |
| 6 | Matrix base at `this+0` | **Falsified** — load is `[this + 0x1C + row*4]` |
| 7 | High-16 early-out is "always pass" | **Falsified** — early-out forces **`*out = 0`** (reject) |
| 8 | Writes filter matrix / mutates this | **Falsified** — leaf read-only TEST/SETNZ; no stores to this |
| 9 | Multiple callers / shared STL helper | **Falsified** — **1** UNCONDITIONAL_CALL only |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |
| 11 | Product demangle sealed (no `_Inferred`) | **Fails** — no RTTI/string for this leaf; keep `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF early-out + bit test | **Confirmed** | Wrong filter accept/reject |
| thiscall + RET 0xC | **Confirmed** | Stack imbalance |
| Matrix @ `this+0x1c`, row/bit `&0x1f` | **Confirmed** | Wrong layout port |
| Sole caller GetObjectsInArea @ `0x004ea560` | **Confirmed** | Mis-system tagging |
| Area-query filter role | **High** | Doc only if wrong |
| High-16 product English | **Low** / open | Misnamed packing rule |
| Per-bit flag meanings | **Low** / open | Wrong gather-mode ports |
| this-object product type | **Low** / open | Wrong owning class name |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean
  CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp

8B 44 24 08          MOV EAX, [ESP+8]        ; a
56                   PUSH ESI
8B D1                MOV EDX, ECX            ; this
8B 4C 24 10          MOV ECX, [ESP+10]       ; b
...
F7 C6 00 00 FF FF    TEST ESI, 0xFFFF0000
75 12                JNZ bit_test
A9 00 00 FF FF       TEST EAX, 0xFFFF0000
74 0B                JZ  bit_test
C6 00 00             MOV BYTE PTR [EAX], 0
C2 0C 00             RET 0xC
...
83 E1 1F             AND ECX, 0x1F
D3 E6                SHL ESI, CL             ; 1 << bit
83 E0 1F             AND EAX, 0x1F
8B 4C 82 1C          MOV ECX, [EDX+EAX*4+0x1C]
0F 95 C1             SETNZ CL
88 08                MOV [EAX], CL
C2 0C 00             RET 0xC

Caller 004ea560: PUSH filterFlags; PUSH [hit+0x1c]; PUSH out*; MOV ECX,EBX; CALL
```

Reject ports that:

- Name this as VOG_DEBUG_STOP / skill helper.
- Use cdecl without popping 12 bytes.
- Treat EAX as boolean return (ignore out-param).
- Index matrix without `& 0x1F` or from `this+0`.
- Invert the high-16 early-out (must reject, not pass).
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: leaf filter gate inside CVOGPhysicsUtils::GetObjectsInArea AABB loop.
// Managed port: bool-like out-param test against a 32x32 bit matrix.

// Pseudo:
// bool AreaQueryFilterBitTest(FilterMatrix self, uint objectType, uint filterFlags)
// {
//     if (((objectType ^ filterFlags) & 0xFFFF0000) == 0 &&
//         (objectType & 0xFFFF0000) != 0)
//         return false;
//     uint row = objectType & 0x1F;
//     uint bit = filterFlags & 0x1F;
//     return (self.BitRows[row] & (1u << bit)) != 0;
// }
//
// Call pattern (parent):
//   if (!AreaQueryFilterBitTest(filterMatrix, hit.TypeAt1C, queryFilterFlags))
//       continue; // skip hit
//   resolve object; append to result list
//
// Known gather filterFlags samples (parent dual, not re-proven here): 1, 0x11, 0x0A.
```

---

## 5. Verdict

Adversarial pass confirms A's CF/ABI/caller/filter-role seal. Residual product English (this-object, high-16 rule, bit meanings) + no runtime → **accept-with-gaps**. Terminal **false**.
