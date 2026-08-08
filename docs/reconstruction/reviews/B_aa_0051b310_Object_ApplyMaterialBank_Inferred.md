# Review B (skeptical / adversarial): `aa_0051b310` Object_ApplyMaterialBank_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b310` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-I) |
| **Counterpart** | `reviews/A_aa_0051b310_Object_ApplyMaterialBank_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a skill-bank cast / ability helper (WQ-009 product skill path) | **Falsified as product role** — callee commits **MatDiffuse/Ambient/Emissive**; no skill id / cast. Residual **address** only. |
| 2 | Vector is classic `std::vector` with begin at `this+0x144` | **Falsified** — null/count tests use **+0x148/+0x14C**; callee uses **header+4/+8**. Header base is +0x144. |
| 3 | Fills empty material bank from gfx | **Falsified** — that is sibling `FUN_0051b2a0` (empty gate inverted). This unit requires **non-empty** bank. |
| 4 | Stack formals / returns a value | **Falsified** — ECX this only; void; bare RET. |
| 5 | `param_1[0x52]` is byte offset 0x52 | **Falsified** — dword index: `0x52*4 = 0x148`. |
| 6 | Sole caller `FUN_004c5510` | **Falsified** — 23 DATA vtable installs + second code xref `0x004f3760`. |
| 7 | Clean invents shader writes inside this body | **Falsified** — body only gates + one call; writes live in `FUN_005194f0`. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Non-empty bank gate + stride 0x10 | **High** | Silent no-op or OOB bank walk |
| Arg order to `FUN_005194f0` | **High** | Swapped gfx/bank → wrong Mat* binds |
| Virtual slot (not free function only) | **High** | Miss polymorphic object types |
| Product English / demangle | Open | Naming only |
| Bank element product type | Open | Port field layout of 0x10 entries |

---

## 3. Cross-check against raw + bytes

```
0051b310  PUSH ECX
          MOV EAX,[ECX+0x148]
          TEST EAX,EAX
          PUSH ESI
          LEA ESI,[ECX+0x144]
          JE  ret
          MOV EDX,[ESI+0x8]      ; end @ +0x14C
          SUB EDX,EAX
          SAR EDX,4
          JE  ret
          MOV EAX,[ECX]
          CALL [EAX+0x1CC]
          TEST EAX,EAX / MOV EAX,[EAX+8] / TEST
          PUSH ESI / PUSH EAX
          CALL FUN_005194f0
          ADD ESP,8
          POP ESI / POP ECX / RET
```

Decompiler `param_1[0x52]` / `param_1+0x51` matches dword indexing of the same offsets.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of Object_ApplyMaterialBank_Inferred (0x0051b310)
void Object_ApplyMaterialBank(Object self)
{
    // bank header @ +0x144; begin +0x148; end +0x14C; stride 0x10
    if (self.MatBankBegin == null) return;
    int n = (self.MatBankEnd - self.MatBankBegin) / 0x10;
    if (n == 0) return;

    var gfx = self.Vtbl_GetGfxComponent(); // vtbl+0x1CC
    if (gfx == null || gfx.MatHost == null) return; // host @ component+8

    MaterialBank_CommitToShader(gfx.MatHost, self.MatBankHeader); // FUN_005194f0
}
```

- Do **not** merge with empty-bank fill (`0x0051b2a0`).
- Do **not** treat as skill cast bank.
- Port as **virtual** on the object vtable family that installs this slot.

---

## 5. Open questions

1. Product name of `vtbl+0x1CC` / material bank class.
2. Whether all 23 vtable owners share identical bank offsets (assumed yes for this method body).
3. Full element layout (owned by `005194f0` dual).

**Verdict:** **accept-with-gaps**
