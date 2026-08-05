# Review B (skeptical / adversarial): `aa_00404d70` GameData_LookupCloneBaseByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404d70_GameData_LookupCloneBaseByCbid.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Returns void (decompiler) | Callers `test eax` / `mov edi,eax` / read `def+0x38` | **Falsified** — returns **void\*** |
| 2 | CALL Lookup then RET | Bytes are **JMP** not CALL | **Falsified** — pure tail |
| 3 | `__cdecl` / no this | Body uses ECX; sites `mov ecx,[DAT_00b041fc]` | **Falsified** — **thiscall** |
| 4 | Allocates / constructs item | Body only hash lookup | **Falsified** — factory is caller (`GiveItemByCbid`) |
| 5 | Hash at wrong offset | Literal `0xF10` in `MOV ECX,[ECX+disp32]` | **Confirmed** `+0xf10` |
| 6 | Key not CBID | CreateCreature logs `"cbid:%d"`; Collect uses req+0x10 CBID | **CBID sealed by usage** |
| 7 | Host is character / inventory | Sites always load global `DAT_00b041fc`, not char this | **Host is global game-data** |
| 8 | Different from CNDHash_LookupByKey | Only remaps this→hash | **Thin wrapper only** |
| 9 | Name "GameData" is product PDB | No plate; role-inferred | **Accept as inferred** — gaps ok |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tail JMP + return value | **High** | Port drops return → always "miss" |
| `this+0xf10` hash | **High** | Wrong table → null defs |
| CBID key domain | **High** for item/creature paths | Non-CBID keys possible elsewhere |
| Host class English | **Medium** | Doc naming only |
| Full value type layout | **Out of unit** | Callers own def+0x38 etc. |

---

## 3. Cross-check against raw / bytes

```
raw decompile: CNDHash_LookupByKey(*(this+0xf10), key); return;
bytes:         MOV ECX,[ECX+0xF10]; JMP Lookup
callers:       MOV ECX,[0x00b041fc]; PUSH cbid; CALL thunk; use EAX
```

Clean must return `void*`, must not invent CALL+discard, must not hardcode global inside the thunk (global is **call-site** ECX setup).

---

## 4. Surviving contract for AutoCore

```csharp
// Client: host method (this usually g_GameData / DAT_00b041fc)
static CloneBaseDef? LookupCloneBaseByCbid(GameDataHost host, uint cbid)
{
    var hash = host.CloneBaseByCbidHash; // this+0xf10
    return CNDHash_LookupByKey(hash, cbid) as CloneBaseDef; // null miss
}

// Typical call site pattern:
// ECX = g_GameData; push cbid; call Lookup; if null fail
```

**Port traps to reject:**

- Implementing as `void` and ignoring return.
- Looking up on character / inventory this instead of game-data host.
- Embedding `DAT_00b041fc` **inside** the thunk (retail loads it at callers).
- Confusing with item **construct** factory (`GiveItemByCbid`) — this is **def lookup only**.

---

## 5. Residual gaps (do not block seal)

1. Product name for host / `DAT_00b041fc`.
2. Complete def layout beyond consumer offsets.
3. Runtime live hit / bit-exact image.
4. Whether any non-CBID key shares this entry (unlikely; not observed).

---

## Verdict

**accept** — adversarial review cannot break the 10-byte tail-thunk contract. Main falsification of scaffold is **void return** and **CALL vs JMP**; main port caution is host ECX source and not inventing construction here.
