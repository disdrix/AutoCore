# Review B (skeptical / adversarial): `aa_004ce940` CVOGLootGenerator_GetOrCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ce940_CVOGLootGenerator_GetOrCreate.md` |
| **System** | loot / economy content (lazy singleton) |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on ensure/get; **reject** void return, “network helper”, and reaction-dispatch-only role |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns **void** | **Falsified** — `mov eax, DAT_00b037e8` then jnz to epilogue with EAX live; ctor result stored and still in EAX |
| 2 | `ExceptionList = pvVar1` is real logic | **Falsified** — SEH restore artifact; `pvVar1` is new buffer, not ExceptionList |
| 3 | This is a CVOGReaction_Dispatch **packet** helper | **Falsified** — no wire/opcodes; pure singleton ensure (scaffold parent name overstated) |
| 4 | Size is not `0xbc` / different manager | **Falsified** — imm `bc 00 00 00`; peer InitGenerators seals CVOGLootGenerator `0xbc` |
| 5 | Ctor is not `FUN_0050c1b0` | **Falsified** — relative call target from bytes; dual names that ctor |
| 6 | Always constructs every call | **Falsified** — `test eax; jnz` short path |
| 7 | Passes object/world args into this unit | **Falsified** — no stack args (`c3` only); table root is **global** `DAT_00b041fc` |
| 8 | Thread-safe Meyers singleton | **Fail as seal** — no critical section / once-flag around create |
| 9 | Scaffold Named_CalleeOf_CVOGReaction_Dispatch is authoritative role | **Overstated** — ~40 diverse callers (equip, tooltip, prefixes, loot gen) |
| 10 | Ready for bit-exact / runtime seal | **Fail** — matrix open |

---

## 2. Decisive dataflow — sealed contract

```
// no stack args
// EAX out = DAT_00b037e8 after ensure

eax = DAT_00b037e8
if (eax != 0) goto epilogue_return_eax

mem = operator_new(0xbc)
if (mem == 0) {
  DAT_00b037e8 = 0
  eax = 0
  goto epilogue
}
// thiscall: ecx = mem, push DAT_00b041fc
eax = FUN_0050c1b0(mem, DAT_00b041fc)
DAT_00b037e8 = eax
epilogue: restore SEH; ret
```

### Byte anchors

| Pattern | Meaning |
|---------|---------|
| `a1 e8 37 b0 00` | `mov eax, [DAT_00b037e8]` |
| `85 c0 75 45` | `test eax; jnz already` |
| `68 bc 00 00 00` | `push 0xbc` |
| `8b 0d fc 41 b0 00` / `51` / `8b c8` | push table root; `mov ecx, mem` |
| `e8 …` → `0050c1b0` | ctor call |
| `a3 e8 37 b0 00` | `mov [DAT_00b037e8], eax` |
| `c3` | ret (no `ret N`) |

---

## 3. Relation attack: peer constructors of same global

| Path | Pattern |
|------|---------|
| **This unit** | ensure/get shared by many runtime call sites |
| `CVOGSectorMap_InitGenerators` | load-time create into same `DAT_00b037e8` |
| Death XP award path | inlined ensure before loot rolls |

All agree on **size `0xbc`** + **ctor `FUN_0050c1b0`** + **global `DAT_00b037e8`**. Name family **CVOGLootGenerator** is peer-plate supported; body itself has no strings.

---

## 4. Adversarial name check

- **Reject** reaction-dispatch / network naming for this body.
- **Accept** `CVOGLootGenerator_GetOrCreate` (or `EnsureCVOGLootGenerator`) as dual canonical.
- **Accept** residual alias `LootManager_GetOrCreate` only if registry prefers the ctor dual’s LootManager label — same object.

---

## 5. Residual risks

1. First-create race without lock.
2. Whether ctor can return non-`mem` pointer (bytes store EAX from ctor — if ctor returns null after partial init, global becomes null while memory may leak — ctor dual returns `this`).
3. No atexit/dtor registration in this unit (locale singleton pattern differs).

**Verdict:** Void/SEH decompiler claims rejected; ensure/get sealed. **accept-with-gaps.**
