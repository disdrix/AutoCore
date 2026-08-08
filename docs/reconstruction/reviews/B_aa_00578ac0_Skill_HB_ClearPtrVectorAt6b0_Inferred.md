# Review B (skeptical / adversarial): `aa_00578ac0` Skill_HB_ClearPtrVectorAt6b0_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578ac0` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B, MEGA-014) |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00578ac0_Skill_HB_ClearPtrVectorAt6b0_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `operator_delete` never returns (Ghidra warning) | Bytes: `ADD ESP,4` then loop / zero stores | **Falsified** — CRT returns |
| 2 | Zero-stores only when buffer null (decompile) | Fall-through after free: three `C7 87 … 0` always run | **Falsified decompile** — always zero |
| 3 | cdecl / stack-arg ABI for this unit | Entry `MOV EDI,ECX`; plain `RET`; caller no push before CALL | **Falsified** — thiscall ECX only |
| 4 | Multiple callers / general utility | `get_function_xrefs` / callers → **1** site in OnEnd | **Falsified multi-caller** — sole OnEnd |
| 5 | Element dtor is scalar deleting dtor only | Body calls `004b99c0` **then** `operator_delete` separately | **Clarify** — teardown core + free (matches dualed NDSpecialFX pattern; not `delete this` fused) |
| 6 | `FUN_004b99c0` is void no-arg (decompile elision) | `MOV ECX,EBX` before CALL | **Falsified no-arg** — thiscall ECX=elem |
| 7 | Vector is `std::list` / intrusive | Stride 4 contiguous; begin/end/cap triad | **Falsified list** — pointer vector shell |
| 8 | Capacity field unused / not present | Explicit store zero to `+0x6b8` | **Sealed present** (capacity-end) |
| 9 | Name is studio-official Skill_* | No RTTI/string on VA; parent OnEnd dual already `_Inferred` | **Tentative** — keep `_Inferred` |
| 10 | This is FireTail / apply-effect path | Only called from OnEnd after resolve; no period/FX stamp | **Falsified FireTail-merge** — clear-only leaf |
| 11 | Missing `ADD ESP,4` (disasm listing gap) | `read_memory` shows `83 C4 04` after both delete calls | **Sealed** — listing incomplete; bytes win |
| 12 | Named_CalleeOf scaffold is authoritative name | No such scaffold for this VA; structural name from layout | **N/A** — no scaffold to retire beyond FUN twin |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-all + zero CF | **High** | Leaks / stale iterators on OnEnd |
| ECX thiscall ABI | **High** | Wrong object cleared |
| Offsets +0x6b0/+0x6b4/+0x6b8 | **High** | Neighbor field corruption |
| Element teardown callee | **High** | Skip FX child-list cleanup |
| Element product type English | **Medium** | Rename churn if not NDSpecialFX subclass |
| Vector field product name | **Low–Medium** | Naming only |
| Sole-caller assumption forever | **High now** | New xrefs would widen role (none today) |

---

## 3. Cross-check: decompile vs bytes

| Step | Decompile | Bytes (`read_memory`) |
|---|---|---|
| this | `param_1` / ECX | `MOV EDI,ECX` |
| walk [begin,end) | yes | ESI load/cmp/`ADD ESI,4` |
| null skip | yes | `TEST EBX` / `JZ` |
| teardown | `FUN_004b99c0()` | `MOV ECX,EBX; CALL 004b99c0` |
| delete elem | warned noreturn | `PUSH; CALL; ADD ESP,4` |
| delete buffer | warned noreturn | same pattern |
| zero triad | only if buf==0 | **always** three `MOV [EDI+off],0` |
| epilogue | return | `POP EDI; POP ESI; RET` |

**Consensus:** accept assembly-corrected CF. Decompiler noreturn + truncated zero path **must not** be ported literally.

---

## 4. Surviving contract for AutoCore

```csharp
// ECX = skill HB this on retail.
static void Skill_HB_ClearPtrVectorAt6b0(SkillHb self)
{
    var begin = self.PtrVec6b0_Begin; // +0x6b0
    var end   = self.PtrVec6b0_End;   // +0x6b4
    for (var it = begin; it != end; it++)
    {
        var p = *it;
        if (p != null)
        {
            NDSpecialFX_TeardownCore(p); // FUN_004b99c0
            NativeDelete(p);
        }
    }
    if (self.PtrVec6b0_Begin != null)
        NativeDelete(self.PtrVec6b0_Begin);
    self.PtrVec6b0_Begin = null;
    self.PtrVec6b0_End = null;
    self.PtrVec6b0_Cap = null; // +0x6b8
}
```

**Port traps to reject:**

- Trusting Ghidra noreturn (would drop zero-stores / loop continue).
- Skipping `FUN_004b99c0` (buffer-only free → FX child leaks / registry residue).
- Calling a fused scalar deleting dtor not present as a single call.
- Treating as stack-arg / stdcall.
- Merging with FireTail / apply-effect units.
- Assuming multi-caller utility beyond OnEnd without new xrefs.

---

## 5. Residual questions

1. What pushes into `+0x6b0` (FireTail sibling / cast path)?
2. Product name of the vector field (target FX list?).
3. Are null slots intentional sparse storage or just defensive?
4. Runtime verification under live OnEnd (Terminal false here).

---

## 6. Verdict

Path B **fails to overturn** CF/ABI/sole-caller/vector-layout seals. Product English remains open → **accept-with-gaps**. Terminal **false**.
