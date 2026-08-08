# Review B (skeptical / adversarial): `aa_004cbdc0` SkillCNDHash_Recreate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbdc0` |
| **VA** | `0x004cbdc0` |
| **Canonical name** | `SkillCNDHash_Recreate_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004cbdc0_SkillCNDHash_Recreate_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + caller assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom EAX/BL ABI like inventory `CNDHash_Recreate` `0x004138d0` | **Falsified** — `push esi; mov esi,ecx`; stack log2; `ret 4` |
| 2 | Lock aborts recreate / process | **Falsified** — log only; destroy/alloc still run (no early ret) |
| 3 | `hash+8` remains bucket **count** after return | **Falsified** — alloc `FUN_004cb410` decrements to **mask** |
| 4 | Stack arg is skill id or rank | **Falsified** — log2; `1 << (cl & 0x1f)` into `+8`; store at `+0x1c` |
| 5 | Same type-identity as inventory CNDHash | **Falsified** — different VA/helpers; ctor peer vtbl `009ce1b8` |
| 6 | Sole caller is CreateOrRecreateSkillHash | **Falsified as sole** — second caller `FUN_004c8f00` push **2** |
| 7 | ECX is owner object | **Falsified** — CreateOrRecreate path loads `ECX=[owner+0x70]` before call |
| 8 | Product class name sealed | **Fails** — vtbl only; `_Inferred` correct |
| 9 | Bit-exact complete | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
// entry
ESI = ECX (hash)
if [ESI+0x1d]: log Recreate-locked; log VOG_DEBUG_STOP
call 004cba60          // ECX = ESI
[ESI+0x1c] = log2 (from stack)
[ESI+8]    = 1 << log2
[ESI+0x18] = 0; [ESI+0x14] = 0
call 004cb410          // ECX = ESI
pop esi; ret 4
```

A ≡ B on live decompile + entry/exit bytes. Nested:

- **Destroy `004cba60`:** zeros count field, freelist-walks, free slab + ptr array (live decompile).
- **Alloc `004cb410`:** requires `0 < *(+0x1c) < 0x11`, builds `n` buckets of 0xc sentinels (`PTR_LAB_009cb970`), then `*(+8)--`.

Caller `0x004c902c` context:

```text
MOV ECX, [EDX+ESI+0x74]   ; MI → hash*
PUSH 2
CALL 0x004cbdc0
```

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Recreate CF | **High** | Skill wipe leaves corrupt map |
| Mask post-condition | **High** | Insert bucket wrong |
| log2 domain 1..16 | **High** (alloc gate) | throw if out of range |
| thiscall vs inventory ABI | **High** | Wrong port calling convention |
| Product class name | **Open** | Naming only |

---

## 4. Surviving contract

```text
// hash* already allocated (sizeof 0x34); may be non-empty
SkillCNDHash_Recreate_Inferred(hash, log2);
// empty hash; mask at +8; lock flag unchanged by this function
// (lock was only read for the soft log)
```

Do **not**:

- treat as soft no-op when locked
- use inventory EAX/BL calling convention
- pass owner as `this`
- merge type with `CNDHash_Recreate` `0x004138d0`

**Verdict:** **accept-with-gaps.** Accept A.
