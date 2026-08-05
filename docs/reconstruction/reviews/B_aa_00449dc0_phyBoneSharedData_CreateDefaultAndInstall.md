# Review B (skeptical / adversarial): `aa_00449dc0` phyBoneSharedData_CreateDefaultAndInstall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00449dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-E) |
| **Counterpart** | `reviews/A_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX-thiscall member | Body never loads ECX as this; uses **EBX+4**; call sites set EBX not ECX | **Falsified** |
| 2 | Installs at bone+0 (or +4 as bone field for qs) | Call sites `LEA EBX,[bone+0xf0]` → `*(EBX+4)=bone+0xf4` | **Falsified** if claimed as bone+0 |
| 3 | Object is a collision shape (string co-located) | String `"Collision shape already set!"` has **no xrefs**; +0x80 is null shape **slot** filled later by BDAT; parent uses object as **phyBoneSharedData** | **Overstated** as whole-type identity |
| 4 | gfxBodyMassageMachine product body | Auto-seed residual; no body strings; callers are phy bone paths | **Falsified** as product name |
| 5 | Copies live runtime matrix (not constant) | `rep movsd` from static `DAT_00afdf70` identity | **Falsified** |
| 6 | Stack stdcall with size arg | `push 0x90` is **new** size only; bare `ret` not `ret n` | **Falsified** |
| 7 | Always non-null result | Null path zeros ESI and still stores null into slot | **Falsified** if claimed |
| 8 | Frees old via operator_delete directly | Release is virtual `vtbl+8` after refcount hit 0 | **Falsified** as direct free |
| 9 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX container / +4 slot ABI | **High** | Wrong wrapper register |
| 0x90 size + identity defaults | **High** | Corrupt shared layout |
| Refcount install/replace | **High** | Leak / double free |
| Slot is bone+0xf4 | **High** | Breaks BDAT + copy path |
| Class English "phyBoneSharedData" | **Med–High** | plate via parent/source path; PDB open |
| Product method spelling | **Low–Med** | Naming only |
| Collision-shape-as-type myth | **High reject** | Wrong subsystem placement |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `56 68 90…`, ends `…89 73 04 5e c3` |
| `g_flOne` / identity matrix | **Yes** byte-sealed |
| Vtbl triple | **Yes** dtor / empty / release helper |
| All 5 callers LEA EBX+0xf0 | **Yes** assembly context |
| Parent PBON then BDAT uses +0xf4 | **Yes** sealed phyBone_unserialize |

**Attack on “this is a collision-shape factory only”:** **Fails as exclusive identity** — object is the shared-data host; +0x80 is a nested shape pointer defaulted to null.

**Attack on “ECX thiscall install at bone+4 qs field”:** **Fails** — EBX container; qs lives inside the allocated object and is later copied by `0096de80`.

---

## 4. Surviving contract for AutoCore

```
// EBX = container*  (retail: LEA EBX, [bone+0xf0])
// *(EBX+4) = RefCounted phyBoneSharedData*
// new 0x90; identity qs (0,0,0,1)+(0,0,0)+(1,1,1); identity 4x4 @+0x40; +0x80=0
// AddRef new; Release old; store; bare ret
```

**Falsified port mistakes:**

- Using ECX as this for the bone.
- Writing the 0x90 object into bone+4 (local qs) instead of bone+0xf4.
- Treating co-located "Collision shape already set!" as proof the whole type is a shape.
- Inventing stack args or `ret 4`.
- Skipping refcount replace (leak / use-after-free).

---

## 5. Open questions

1. Product/PDB method name.
2. Full type English for `DAT_00d1eac0` / field +0x08.
3. Runtime / bit-exact.

**Verdict:** **accept** — sealed CF/ABI/layout; reject ECX / gfxMassage / pure-shape myths.
