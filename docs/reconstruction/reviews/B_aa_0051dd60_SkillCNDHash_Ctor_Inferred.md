# Review B (skeptical / adversarial): `aa_0051dd60` SkillCNDHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051dd60` |
| **VA** | `0x0051dd60` |
| **Canonical name** | `SkillCNDHash_Ctor_Inferred` |
| **Review date** | `2026-08-04` (WQ9D-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051dd60_SkillCNDHash_Ctor_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Void ctor (no return) | **Falsified** — `mov eax,esi`; decompiler returns `param_1`; create path stores EAX |
| 2 | Allocates its own memory | **Falsified** — placement-style on ECX; caller `operator_new(0x34)` |
| 3 | sizeof is skill runtime (~0x630) | **Falsified** — hash header **0x34** only |
| 4 | log2 is skill id | **Falsified** — drives `1<<log2` bucket count |
| 5 | Multi-caller fan-in | **Falsified** — sole code xref `00518e30` create path |
| 6 | Same ctor as inventory CNDHash | **Falsified** — vtbl `009ce1b8` skill family |
| 7 | Zeros entire 0x34 block | **Falsified** — **`+0x24` not written**; also `+0x1e/+0x1f` only via adjacent stores pattern (log2/lock only at 1c/1d) |
| 8 | Sets traversal lock true | **Falsified** — `+0x1d = 0` (clear) |
| 9 | Product name sealed | **Fails** — `_Inferred` |
| 10 | Bit-exact complete | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
ESI = ECX (block)
[ESI] = 009ce1b8
[ESI+4]=0; [ESI+0xc]=0
[ESI+8] = 1 << log2
[ESI+0x10..0x18]=0
[ESI+0x1c]=log2; [ESI+0x1d]=0
[ESI+0x20]=0
// skip +0x24
[ESI+0x28..0x30]=0
call 004cb410   // ECX=ESI
EAX = ESI; ret 4
```

A ≡ B. Parent create path:

```text
push 0x34; operator_new
if non-null: ECX=block; push log2; call 0051dd60; store [owner+0x70]
else: store 0
```

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor CF + vtbl | **High** | Wrong type on skill hash slot |
| sizeof 0x34 | **High** | Heap corruption |
| Return this | **High** | Null slot if ignored |
| +0x24 skip | **High** | Over-clean invents zero |
| Product name | Open | Naming |

---

## 4. Surviving contract

```text
void* block = operator_new(0x34);
SkillCNDHash* h = block
  ? SkillCNDHash_Ctor_Inferred(block, log2)
  : nullptr;
owner->skillHash = h; // +0x70
// ret 4 from parent; ctor itself returns h in EAX
```

Do **not**:

- invent zero of `+0x24`
- treat as skill-object ctor size
- merge with inventory CNDHash ctor identity
- claim multi-owner direct callers

**Verdict:** **accept-with-gaps.** Accept A.
