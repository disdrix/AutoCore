# Review B (skeptical / adversarial): `aa_00748960` MeshHost0xC4_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00748960` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-H) |
| **Counterpart** | `reviews/A_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack-arg cdecl ctor | **Falsified** — ECX thiscall/fastcall; no stack formals; plain RET |
| 2 | Returns void / status code | **Falsified** — `MOV EAX,ESI` returns self |
| 3 | Object size ≠ 0xC4 | **Falsified** — last stores to +0xC0; all host-table callers `new(0xC4)` |
| 4 | Single vtbl only | **Falsified** — three vtbl slots (+0x00/+0x04/+0x08) |
| 5 | `DAT_00aaa630` is a pointer | **Falsified** — float load path `movss`; bytes `0x7f7fffff` = +FLT_MAX |
| 6 | Name "Mesh" is product plate | **Careful** — structural from caller pattern (`new(0xC4)` mesh host / TacArc / fluid); keep `_Inferred`; no PDB demangle |
| 7 | Dead / unused | **Falsified** — 45 xrefs / 25 callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX + return this | **High** | Wrong ABI |
| Size 0xC4 | **High** | Buffer OOB on port |
| ±FLT_MAX defaults | **High** | Wrong AABB init |
| Flag 0x81 @ +0xBC | **High** (bytes) | Flag misuse only |
| Product English | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 336 B hex ends `8bc6 5e 5b 64 89 0d … 83 c4 10 c3`.
- Prologue: SEH + `51 53 56` (ECX EBX ESI); `8B F1` = this→ESI.
- Neighbor `FUN_00748ab0` clears bit0 of `+0xBC` — confirms flag field liveness.
- W35-E HostPtrTable12 always pairs this ctor with dual-vtbl **override** of +0x00/+0x04 after return — base vtbls are intermediate, not final for those slots.

---

## 4. Surviving contract for AutoCore

```
// Port as ECX placement ctor of fixed 0xC4 mesh-host shell:
MeshHost* MeshHost0xC4_BaseCtor(MeshHost* self /* ECX */) {
  // multi-vtbl, vector 2x8, zeros, FLT_MAX triples, sub@+0x78, flags|=0x81
  return self;
}
// Callers often immediately overwrite vtbl[0]/vtbl[1] with subclass dual pair.
// Do not invent product class name without PDB.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, size, multi-vtbl, ±FLT_MAX, flag OR, return this. Residual product English only → **accept**.
