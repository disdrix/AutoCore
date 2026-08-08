# Function record: ServerCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b350` |
| **Canonical name** | `ServerCreateFromPacket` |
| **Ghidra name** | `FUN_0051b350` |
| **Address** | `0x0051b350`–`0x0051b54e` (**510 B** / `0x1FE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-spawn / network create (client) |
| **Completion status** | **Dual sealed** (A+B 2026-08-04 WQ9R-I) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Product plate: profiler zone + error string **`ServerCreateFromPacket`** @ `0x009cee68` / COID fail suffix `(in ServerCreateFromPacket)`.

## Purpose

Create and identity-init a client object from a server create packet: unpack CBID+COID, optional CBID remap map, `CVOGReaction_GiveItemByCbid`, `vtbl+8` init, stamp COID @ `+0x160`, `vtbl+0x20` identity, optional `+0x17c |= 0x80` when remapped.

## Signature (sealed)

```c
void * /* object* */ ServerCreateFromPacket(void *stream /* stack0 */, void *host /* stack1 */);
// caller-clean (bare RET); returns object* or null
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b350_FUN_0051b350.md`
- Annotated: `docs/reconstruction/raw/aa_0051b350_FUN_0051b350.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ServerCreateFromPacket.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0051b350.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051b350_ServerCreateFromPacket.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051b350_ServerCreateFromPacket.md`
- Report: `docs/agents/task-dual-ab-0051b310-0051b350-wq9ri-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callees | `Profiler_EnterNamedZone` / `Leave`, `FUN_00787d40`, `Map_LowerBoundFindByIntKey`, `CVOGReaction_GiveItemByCbid`, `FUN_007a4480`, `FUN_0040fb90`, `FUN_00403430` |
| Callers | **None recovered** in Ghidra (indirect / gap) |
| Related | `AllocateNewObjectFromCbid` (`0x004cf120`) — sibling factory without packet COID |

## Confidence

| Claim | Level |
|---|---|
| Product name ServerCreateFromPacket | **High** (plates) |
| Stream/host args, unpack sizes, COID offsets | **High** (bytes) |
| unaff_EDI map trap | **Confirmed false** |
| Call graph | Open (no xrefs) |
| Fail-path list node types | Medium / gap |
