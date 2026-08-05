# Review B (skeptical / adversarial): `aa_00444a40` Sto_UnserialFactoryMapB_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444a40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W36-C) |
| **Counterpart** | `reviews/A_aa_00444a40_Sto_UnserialFactoryMapB_InsertCreator_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ caller decompiles for tags). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Uses MapA (`FUN_00438c40`) | All three GetInstance relocs → `00438ca0` | **Falsified if MapA** |
| 2 | Is GetInstance / Meyers singleton | Body finds/inserts/logs; not once-flag | **Falsified** |
| 3 | ECX-thiscall method | No ECX this setup; stack tag; plain RET | **Falsified** |
| 4 | Skips bind on duplicate | Always `MOV [node+0xC],EBX` after both paths | **Falsified if "skip"** — rebinds always |
| 5 | `unaff_EBX` is decompiler noise | Final store is `MOV [EAX+0xC],EBX` | **Falsified** — EBX is intentional formal |
| 6 | Same static bag as MapA insert | MapB bag `DAT_00d1fcec` vs MapA `DAT_00d1fd18` | **Must keep separate** |
| 7 | Palantir / gfxBody product (scaffold) | Header string stoAbstractUnserializationFactory.h | **Reject scaffold** |
| 8 | Only inserts, never updates creator | Store after both branches | **Updates/rebinds** |
| 9 | Tag is string | Stack dword; callers pass FourCC immediates | **uint32_t FourCC** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Map B target | **High** | Cross-map registration |
| Dup log + still rebind | **High** | Silent wrong creator |
| EBX creator formal | **High** | Lost ABI |
| Stack tag formal | **High** | Wrong key |
| Creator C type | **Low / open** | Port compile errors |
| Product English | **Medium** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw: GetB; sentinel; GetB; find; maybe log; GetB; find; maybe insert; *node+0xC=EBX
bytes: three CALL 438ca0; CALL find×2; optional vog_LogMessage; CALL insert; MOV [EAX+0xC],EBX; RET
```

Clean must **not** invent:

- MapA GetInstance
- Skipping the `+0xC` store on duplicate
- ECX this
- String keys
- NestedHash ctor inside this body

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00444a40 — Map B only
// EBX = creator (register); tag = stack uint FourCC
void Sto_UnserialFactoryMapB_InsertCreator(uint tag, IntPtr creatorFn)
{
    var bag = Sto_UnserialFactoryMapB_GetInstance();
    var sentinel = bag.Sentinel; // +0x08
    var node = NestedHash_Find(bag, tag);
    if (node != sentinel)
        LogDuplicateCreatorTag(); // header line 0x24 sev 2
    node = NestedHash_Find(bag, tag);
    if (node == sentinel)
        node = NestedHash_Insert(bag, tag, 0);
    node.CreatorAt0x0C = creatorFn; // always
}
```

**Port traps:** using MapA; dropping EBX rebind on dup; treating as thiscall.

---

## 5. Verdict

**accept-with-gaps** — adversarial separation from MapA/GetInstance/scaffold holds; creator type residual.
