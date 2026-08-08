# Review B (skeptical / adversarial): `aa_0041c140` StdVector_CopyCtor_Elem0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-022) |
| **Counterpart** | `reviews/A_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is assign-operator / replace | **Falsified** — buy zeros triple then alloc; no `operator_delete` of old buffer |
| 2 | This is bare uninitialized_copy (like `0040a600`) | **Falsified** — owns count+buy+publish end; thiscall dest shell; different callees |
| 3 | Same unit as SkillSet Ucopy `0040a600` | **Falsified** — `0040a600` is cdecl range Ucopy ECX=end; this is vector copy-ctor |
| 4 | Same as leaf Ucopy `00442b00` | **Falsified** — different ABI/role/address |
| 5 | `RET` cdecl / no this | **Falsified** — **`RET 4`** (`C2 04 00`); `MOV EDI,ECX`; callers load ECX |
| 6 | Element stride not 0x18 | **Falsified** — `/ 0x18` in body; buy `n*0x18`; Ucopy +6 dwords |
| 7 | Tree insert / rebalance itself | **Falsified** — pure vector construct; parent/buynode own tree |
| 8 | Freelist / CNDHash helper | **Falsified** — operator_new path via buy; no freelist head |
| 9 | Product name `SkillSet_*` required | **Falsified as required name** — stride matches SkillSet family but no product string/type plate here; keep generic StdVector |
| 10 | Named_CalleeOf / VOG_DEBUG chain is product | **Falsified** — caller-chain scaffold only |
| 11 | Runtime Confirmed | **Rejected** — no Launcher / no live probe this dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Copy-ctor CF (count→buy→Ucopy→end) | **High** | Wrong lifecycle (leaks / double-free) |
| ABI thiscall + RET 4 | **High** | Stack corruption |
| Stride 0x18 / layout +4/+8/+0xC | **High** | Wrong element size / offsets |
| Node value vector @ +0x10 | **High** | Wrong map value plate |
| Buy / Ucopy residual pairing | **High** (raw) | Wrong if callees misread |
| Element product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy — never Confirmed here |

---

## 3. Cross-check against parent insert + peers

```
// R12-011 dualed always-insert 0041ba30:
//   thiscall map; ret 0x10; char key; buynode 0041d860; node 0x24; isnil@+0x21
// Buynode 0041d860 (undualed evidence):
//   operator_new(0x24); key@+0x0C; LEA ECX,[node+0x10]; CALL 0041c140; color@+0x20
// This unit 0041c140:
//   vector copy-ctor into ECX shell; elem 0x18; ret 4
// Peer SkillSet Ucopy 0040a600 (dualed MEGA-055):
//   range Ucopy only; cdecl; ECX=end — DO NOT MERGE
// Peer leaf Ucopy 00442b00:
//   register ABI; no SEH buy path — DO NOT MERGE
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared StdVector copy-ctor for elem size 0x18:
//  - thiscall; ret 4; (dest=ECX, src=stack); EAX=dest
//  - VecShell: begin@+4, end@+8, capacity_end@+0xC
//  - count = begin? (end-begin)/0x18 : 0
//  - buy residual 0041c250 (zero triple; new count*0x18)
//  - Ucopy residual 00422580 (6-dword POD); dest.end = result
//  - empty source → zeroed empty vector
// Pair with char-key buynode 0041d860 / always-insert 0041ba30 (value @ node+0x10).
// Do not merge with SkillSet range Ucopy 0040a600, leaf 00442b00, or tree insert.
// Do not claim Runtime Confirmed without a separate live probe.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/copy-ctor role/disambiguation from Ucopy peers. Product + element English residual → **accept-with-gaps**. Runtime Confirmed: **not claimed**.
