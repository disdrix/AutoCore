# Review B (skeptical / adversarial): `aa_004063a0` CNDHash_Ctor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004063a0` |
| **VA** | `0x004063a0` |
| **Canonical name** | `CNDHash_Ctor_00a2c2b0` |
| **Review date** | `2026-08-04` (WQ9H-D dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + caller context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Standard **thiscall** (ECX=this, stack log2) like SkillCNDHash_Ctor | **Falsified** — `MOV ESI,[ESP+…]`; CL=log2; caller pushes this then sets CL |
| 2 | Ghidra `__thiscall(byte, this*)` role-correct | **Falsified** as thiscall identity — param order is decompiler fiction; machine is CL/stack |
| 3 | Merges with skill ctor `0x0051dd60` / stamp `009ce1b8` | **Falsified** — different VA, vtbl imm `00a2c2b0`, inverted ABI |
| 4 | Writes all 0x34 bytes / zeroes +0x24 | **Falsified** — +0x24 gap intentional (sibling pattern) |
| 5 | Alloc is thiscall on ECX | **Falsified** — ESI custom; WQ9G-J sealed |
| 6 | Multiple create sites / variable log2 | **Falsified for production sole xref** — one CALL, hard-coded CL=2 |
| 7 | Product class English sealed | **Fails** — stamp-qualified name only |
| 8 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry (after SEH)
// CL = log2 (caller MOV CL,2)
// [stack after frame] = self (caller PUSH new(0x34))
EDX = 0
EAX = 1 << CL
ESI = self
[ESI]     = 0x00a2c2b0
[ESI+8]   = EAX                  // COUNT
[ESI+4]=[ESI+0xc..0x18]=0
[ESI+0x1c]= CL; [ESI+0x1d]=0
[ESI+0x20]=0; [ESI+0x28..0x30]=0  // skip +0x24
CALL 0x00406f20                  // ESI preserved = self
EAX = ESI
ret 4
```

A ≡ B on live decompile CF + entry/exit bytes + sole caller site.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor CF + field map | **High** | Wrong host layout / mask seed |
| CL/stack ABI vs thiscall | **High** | Silent ABI break on port |
| vtbl / stamp family link | **High** | Cross-family type merge |
| Product English | **Open** | Naming only |
| OOM from nested alloc | **Open** | Nested throw path only |

---

## 4. Surviving contract

```text
CNDHash_Ctor_00a2c2b0:
  CL = log2; stack self*; ret 4; EAX = self
  install vtbl 00a2c2b0; seed count=1<<log2; clear fields; skip +0x24
  ESI-call AllocBucketTable_00a2c2e4
```

**Verdict:** **accept-with-gaps**
