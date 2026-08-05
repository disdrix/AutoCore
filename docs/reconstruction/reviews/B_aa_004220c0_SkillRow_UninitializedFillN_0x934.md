# Review B (skeptical / adversarial): `aa_004220c0` SkillRow_UninitializedFillN_0x934

| Field | Value |
|---|---|
| **Stable ID** | `aa_004220c0` |
| **VA** | `0x004220c0` |
| **Canonical name** | `SkillRow_UninitializedFillN_0x934` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-M) |
| **Counterpart** | `reviews/A_aa_004220c0_SkillRow_UninitializedFillN_0x934.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function takes vector* in ECX (emplace decompiler residual) | Body uses ECX as countdown; emplace site sets `ecx=1` | **Falsified** “ECX=vector” |
| 2 | Source advances with destination | Body reloads ESI from EBX each iteration; EBX fixed | **Falsified** streaming-src claim |
| 3 | Constructs C++ objects (ctors) | Only `rep movsd` — no calls | **Falsified** |
| 4 | Returns end pointer | Bare `ret`; EAX advanced but not a documented ABI return for this symbol | **Partial** — parents that need end compute it themselves (`0041c9a0`) |
| 5 | Stride is something other than 0x934 | Immediate `add eax,0x934`; dword count 0x24d | **Falsified** |
| 6 | Name implies exclusive skill use | Current 3 xrefs are skill-vector family; pattern is generic fill-N | **Accepted naming risk** — structural name ties to known parents; still correct for this dual |
| 7 | `jbe` treats negative count as zero | unsigned compare; negative becomes large | **Survives as caller contract** — parents pass non-negative |

---

## 2. Surviving contract

```
FillN(count=ECX, dst=EAX, src=EBX):
  if count == 0: return
  while count--:
    if dst: memcpy(dst, src, 0x934)   # rep movsd 0x24d
    dst += 0x934
```

Ports of skill-row vector grow/emplace must stamp **entire 0x934-byte** prototype (not field-wise partial copy) when filling new capacity.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride / dword count | **High** | corrupt adjacent vector memory |
| Register ABI | **High** | wrong fill / garbage rows |
| Leaf POD | **High** | missing ctor side effects if wrongly assumed |
| Product field map | n/a here | owned by loader duals |

---

## 4. Cross-check against raw + bytes

```
test ecx / jbe
mov edx,ecx
loop: test eax / jz skip / mov ecx,0x24d / mov esi,ebx / mov edi,eax / rep movsd
      add eax,0x934 / sub edx,1 / jnz loop
ret
```

Clean must not invent constructors, stack formals, or a required return value.

---

## 5. Open questions

1. Full skill-row field glossary (parent).
2. Whether AutoCore should share a generic `UninitializedFillN(stride)` helper vs specialized 0x934.

**Verdict:** **accept**
