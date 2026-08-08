# Review B (skeptical / adversarial): `aa_005ffc80` EmptyStub_Ret4

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-009) |
| **Counterpart** | `reviews/A_aa_005ffc80_EmptyStub_Ret4.md` |
| **Verdict** | **accept** (trivial CF; residual is naming/catalog only) |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Body does real work (flags, free, notify, init dest) | **Falsified** — sole body `c2 04 00` |
| 2 | Skills-abilities product method (partition system tag) | **Falsified as purpose** — mass multi-domain DATA reuse; tag is residual parent score host |
| 3 | Bare `ret` / same ABI as `EmptyRet` `0x0056f570` | **Falsified** — this is **`ret 4`**; EmptyRet is bare `c3` |
| 4 | Same unit as neighbor `FUN_005ffc90` | **Falsified** — different VA; neighbor has real callees |
| 5 | Decompiler `void(void)` is complete ABI | **Falsified** — machine cleans 4 stack bytes |
| 6 | Returns meaningful EAX | **Unfounded** — no `mov eax` in body |
| 7 | `FUN_0064d9f0` depends on stub to initialize dest | **Falsified** — stub is nop; caller then overwrites 8 dwords |
| 8 | Clean should invent domain body for VehicleAction / Class_00a9bbe8 | **Falsified** — clean must stay empty; slots default here |
| 9 | Pure thiscall with zero stack args | **Falsified** — `ret 4` requires one stack dword cleaned |
| 10 | Alloc / construct / dtor implementation | **Falsified** — no callees, no stores |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure nop body | **High** | inventing side effects breaks all vtbl defaults |
| Shared leaf identity | **High** | splitting into fake per-domain functions |
| `ret 4` (callee stack cleanup) | **High** | wrong port ABI vs bare-`c3` EmptyRet |
| Not skills-abilities-specific | **High** | wrong ownership / wrong system tag |
| Not alias of EmptyRet | **High** | stack imbalance if merged incorrectly |

---

## 3. Cross-check against raw + bytes

```
EmptyStub_Ret4:
  ret 4    ; c2 04 00
```

Any clean plate with branches, stores, string handling, or bare `ret` without documenting stack cleanup is **wrong**.

Physics notes that call this "empty `ret`" are **underspecified** (omit stack cleanup) but not CF-conflicting.

---

## 4. Surviving contract for AutoCore

```c
// Port: shared empty leaf with ret 4 (do not special-case by caller domain)
void EmptyStub_Ret4(void * /*ignored*/) { /* no-op; ret 4 */ }

// Vtbl defaults may point here; overrides are separate VAs with real bodies.
// Distinct from EmptyRet (bare c3 @ 0x0056f570) — do not collapse ABIs.
// FUN_0064d9f0 CALL is a nop; port may omit the call and keep the field copy only.
```

---

## 5. Open questions

1. PDB / CRT symbol string.
2. Whether server ports need an equivalent shared nop address (usually omit empty vfuncs; if present, preserve **ret 4**).

**Verdict:** **accept**
